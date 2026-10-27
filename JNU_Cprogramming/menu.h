#pragma once
#ifndef __EXPERIMENT_MENU_H
#define __EXPERIMENT_MENU_H

#include <stdio.h>
#include <windows.h>

#define MAX_EXP_NUM 10
#define MAX_FILE_PER_EXP 30
#define FILE_NAME_LEN 64

// 存储每个实验对应的所有源码文件名
char expFileList[MAX_EXP_NUM + 1][MAX_FILE_PER_EXP][FILE_NAME_LEN];
// 每个实验的文件总数
int expFileCount[MAX_EXP_NUM + 1] = {0};

// 实验菜单标题说明，和你作业要求一一对应
const char expDesc[MAX_EXP_NUM + 1][256] = {
    "", // 0占位不用
    "实验作业1\nChapter2 P56【G】(b)(c)(d)\nChapter3 P79【B】(d,e,f,h)\nChapter3 P82【E】(c,d,e,f)\nChapter4 P96【C】【D】",
    "实验作业2\nP126 【D】(a)(c)(e)",
    "实验作业3\nP127 【F】(b)\nP130 【J】(a/b/c/d/e/f/g/h/k)",
    "", // 实验4无题目
    "实验作业5\nP197【D】(a/b1/b2/b3/c/d/e)",
    "实验作业6\nP204【L】(b)(c)(d)",
    "实验作业7\nP229【D】(c)(d) 【F】(d)(f)(h)(i)",
    "实验作业8\nP248【D】(f/g/h/i/j)",
    "实验作业9\nP262 【D】(a)(b)",
    "实验作业10\nP291 【C】(g)(h)"
};

// 函数声明
void ScanAllExperimentFiles(void);
void PrintSourceCode(const char *fileName);
int FirstMenu(void);
int SecondMenu(int expNo);
void RunExperimentFile(const char *fileName);

#endif
