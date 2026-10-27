#include <stdio.h>

void main()
{
	int	matrix[4][4];
	int i,j,temp;
	
	for (i=0; i<4; i++) 
	{
        for (j=0; j<4; j++) 
		{
            matrix[i][j] = rand() % 100; 
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
    
    printf("transpose of matrix\n");
    for(i=0;i<4;i++)
    {
    	for(j=i+1;j<4;j++)
    	{
    		temp = matrix[i][j];
    		matrix[i][j] = matrix[j][i];
    		matrix[j][i] = temp;
		}
	}
	for (i=0; i<4; i++) 
	{
        for (j=0; j<4; j++) 
		{
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}
