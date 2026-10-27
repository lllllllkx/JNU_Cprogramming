//without using recursion
#include <stdio.h>
int sumdigit(int n)
{
	int sum = 0;
	while(n>0)
	{
		sum += n % 10;
		n /= 10;
	}
	return sum;
} 
void main()
{
	int num,sum;
	printf("Enter a 5-digit positive integer:");
	scanf("%d",&num);
	sum = sumdigit(num);
	printf("%d",sum);
}
