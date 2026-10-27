#include <stdio.h>

int main()
{
	int i = 1;
	double num = 1.0;
	double sum = 0.0;
	
	for(i=1;i<8;i++)
	{
		num *= i;
		sum += i/num;
	}
	printf("%f",sum);
	
	return 0; 
} 
