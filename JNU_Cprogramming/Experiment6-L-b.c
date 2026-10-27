#include <stdio.h>

void main()
{
	int	matrix[5][5];
	int i,j;
	int max = matrix[0][0];
	
	for (i=0; i<5; i++) 
	{
        for (j=0; j<5; j++) 
		{
            matrix[i][j] = rand() % 100; 
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			if(max<matrix[i][j])
				max = matrix[i][j];
		}
	}
	printf("the largest number is %d",max);
} 
