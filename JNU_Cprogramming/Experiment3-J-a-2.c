//using recursion
#include <stdio.h>
int sumdigit(int n)
{
	int sum;
	if(n==0)
		return 0;
	else
		sum = n % 10 + sumdigit(n/10);
} 
void main()
{
	int num,sum;
	printf("Enter a 5-digit positive integer:");
	scanf("%d",&num);
	sum = sumdigit(num);
	printf("%d",sum);
}
