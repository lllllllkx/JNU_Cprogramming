#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include "menu.h"

// 扫描当前目录所有ExperimentN-*.c，分组存入expFileList
void ScanAllExperimentFiles(void)
{
    WIN32_FIND_DATA findData;
    HANDLE hFind;
    char searchPath[] = "Experiment*.c";
    char fullFileName[FILE_NAME_LEN];
    hFind = FindFirstFile(searchPath, &findData);
    if (hFind == INVALID_HANDLE_VALUE)
    {
        printf("未找到任何实验源码文件！\n");
        return;
    }
    do
    {
        if (!(findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
        {
            strcpy(fullFileName, findData.cFileName);
            // 提取实验号：ExperimentX-xxx.c 中的 X
            int expNo = 0;
            sscanf(fullFileName, "Experiment%d-", &expNo);
            if (expNo >= 1 && expNo <= MAX_EXP_NUM)
            {
                int idx = expFileCount[expNo];
                if (idx < MAX_FILE_PER_EXP)
                {
                    strcpy(expFileList[expNo][idx], fullFileName);
                    expFileCount[expNo]++;
                }
            }
        }
    } while (FindNextFile(hFind, &findData));
    FindClose(hFind);
}

// 打印指定.c文件全部源代码
void PrintSourceCode(const char *fileName)
{
    FILE *fp = fopen(fileName, "r");
    if (fp == NULL)
    {
        printf("打开文件失败：%s\n", fileName);
        return;
    }
    char buf[1024];
    printf("==================== 源码：%s ====================\n", fileName);
    while (fgets(buf, sizeof(buf), fp) != NULL)
    {
        printf("%s", buf);
    }
    printf("=================================================\n\n");
    fclose(fp);
}

// 运行对应实验程序（gcc编译运行）
void RunExperimentFile(const char *fileName)
{
    char cmd[256];
    sprintf(cmd, "gcc %s -o temp_run.exe && temp_run.exe", fileName);
    printf("开始编译并运行 %s ...\n\n", fileName);
    system(cmd);
    system("del temp_run.exe");
}

// 一级菜单
int FirstMenu(void)
{
    int input,i;
    while (1)
    {
        system("cls");
        printf("姓名：李可欣  学号：2024102701\n");
		printf("===== C语言实验作业总菜单 =====\n");
        printf("请输入数字选择，按Enter确认\n\n");
        printf("    0 - 退出程序\n");

        // 打印所有实验选项
        for (i = 1; i <= MAX_EXP_NUM; i++)
        {
            printf("    %d - 实验%d\n", i, i);
        }
        printf("    %d - 查看 A-menu.c 源码\n", MAX_EXP_NUM + 1);

        printf("\n请输入选择(0~%d)：", MAX_EXP_NUM + 1);
        if (scanf("%d", &input) != 1)
        {
            // 清空错误输入缓冲区
            while (getchar() != '\n');
            printf("输入无效，请输入数字！按任意键继续...\n");
            _getch();
            continue;
        }

        if (input >= 0 && input <= MAX_EXP_NUM + 1)
        {
            return input;
        }
        else
        {
            printf("输入超出范围！按任意键继续...\n");
            _getch();
        }
    }
}

// 二级菜单
void ShowExpFileMenu(int expNo)
{
    int input,i;
	int fileTotal = expFileCount[expNo];
    if (fileTotal == 0)
    {
        printf("当前实验无任何源码文件！按任意键返回\n");
        _getch();
        return;
    }

    while (1)
    {
        system("cls");
        printf("%s\n\n", expDesc[expNo]);
        printf("输入数字选择文件运行 | 输入0返回主菜单\n\n");
		printf("    0 - 返回主菜单\n");
        for (i = 0; i < fileTotal; i++)
        {
            printf("    %d - %s\n", i + 1, expFileList[expNo][i]);
        }

        printf("\n请输入选择(0~%d)：", fileTotal);
        if (scanf("%d", &input) != 1)
        {
            while (getchar() != '\n');
            printf("输入无效，请输入数字！按任意键继续...\n");
            _getch();
            continue;
        }

        if (input == 0)
        {
            // 输入0退出二级菜单，回到一级主菜单
            return;
        }
        else if (input >= 1 && input <= fileTotal)
        {
            // 选中文件，查看源码+运行
            int fileIdx = input - 1;
            const char *targetFile = expFileList[expNo][fileIdx];
            PrintSourceCode(targetFile);
            RunExperimentFile(targetFile);
            printf("\n执行完毕，按任意键回到本实验文件列表\n");
            _getch();
        }
        else
        {
            printf("输入超出范围！按任意键继续...\n");
            _getch();
        }
    }
}

int main(void)
{
    // 启动扫描所有实验文件
    ScanAllExperimentFiles();
    while (1)
    {
        int opt = FirstMenu();
        system("cls");

        // 输入0直接退出程序
        if (opt == 0)
        {
            printf("感谢使用，按任意键程序退出！\n");
            system("pause");
            return 0;
        }
        // 进入对应实验循环菜单
        else if (opt >= 1 && opt <= MAX_EXP_NUM)
        {
            ShowExpFileMenu(opt);
        }

        else if (opt == MAX_EXP_NUM + 1)
        {
            PrintSourceCode("A-menu.c");
            printf("查看完毕，按任意键返回\n");
            _getch();
        }
    }
    return 0;
}
