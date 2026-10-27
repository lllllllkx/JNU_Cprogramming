#include <stdio.h>
#include <conio.h>
#include <windows.h>

int getkey();
int is_sorted(int p[4][4]);

int main()
{
    int puzzle[4][4] = {
        {1,  4, 15, 7},
        {8, 10,  2, 11},
        {14, 3,  6, 13},
        {12, 9,  5, 0}
    };
    int blank_x = 3;
    int blank_y = 3;
    int i, j;
    int moves = 0;
    int key;

    do
    {
        system("cls");
        printf("===== Number Puzzle Game =====\n");
        printf("Operation: Right key moves left number right | Down key moves upper number down | Up/Left key no action\n");
        printf("Current steps: %d\n\n", moves);

        for (i = 0; i < 4; i++)
        {
            for (j = 0; j < 4; j++)
            {
                if (puzzle[i][j] != 0)
                    printf("%2d ", puzzle[i][j]);
                else
                    printf("__ ");
            }
            printf("\n");
        }
        printf("\nPress arrow keys to operate...\n");

        key = getkey();
        switch (key)
        {
            case 77:
                if (blank_y > 0)
                {
                    puzzle[blank_x][blank_y] = puzzle[blank_x][blank_y - 1];
                    puzzle[blank_x][blank_y - 1] = 0;
                    blank_y--;
                    moves++;
                }
                break;
            case 80:
                if (blank_x > 0)
                {
                    puzzle[blank_x][blank_y] = puzzle[blank_x - 1][blank_y];
                    puzzle[blank_x - 1][blank_y] = 0;
                    blank_x--;
                    moves++;
                }
                break;
            case 75:
            case 72:
            default:
                break;
        }
    } while (!is_sorted(puzzle));

    system("cls");
    printf("===== Game Win =====\n");
    printf("All numbers are arranged in ascending order!\n");
    printf("Total moves: %d\n", moves);
    return 0;
}

int is_sorted(int p[4][4])
{
    int num = 1;
    int i,j;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (num <= 15)
            {
                if (p[i][j] != num)
                    return 0;
                num++;
            }
            else
            {
                if (p[i][j] != 0)
                    return 0;
            }
        }
    }
    return 1;
}

int getkey()
{
    while(!_kbhit());
    int ch = _getch();
    if(ch == 224)
    {
        ch = _getch();
        return ch;
    }
    return ch;
}
