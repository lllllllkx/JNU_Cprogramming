#include <stdio.h>
int main()
{
    int num[100];
    int i, j;
    for(i = 0; i < 100; i++)
    {
        num[i] = i + 1;
    }
    for(i = 1; i < 100; i++)
    {
        if(num[i] != 0)
        {
            for(j = 2 * num[i] - 1; j < 100; j += num[i])
            {
                num[j] = 0;
            }
        }
    }
    printf("Prime numbers from 1 to 100:\n");
    for(i = 1; i < 100; i++)
    {
        if(num[i] != 0)
        {
            printf("%d ", num[i]);
        }
    }
    return 0;
}
