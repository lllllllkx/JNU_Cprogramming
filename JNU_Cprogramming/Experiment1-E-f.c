#include <stdio.h>

int main() 
{
    int i, j;
    for (i = 0; i < 7; i++) 
	{
        for (j = 0; j < 7 - i; j++)
            printf("%c ", 'A' + j);
        for (j = 0; j < 4 * i - 2; j++)
            printf(" ");
        if(i==0)
        {
        	for (j = 6 - i; j > 0; j--)
        	{
        	printf("%c ", 'A' + j - 1);
			}
		}
		
		else
		{
			for (j = 7 - i; j > 0; j--)
        	{
        	printf("%c ", 'A' + j - 1);
			}
		}
            
        printf("\n");
    }
    return 0;
}
