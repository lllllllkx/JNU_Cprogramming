#include <stdio.h>
int binary(int n)
{
	if(n==0)
		return 0;
	binary(n/2);
	printf("%d",n%2);
}
void main()
{
	int n;
	printf("Enter a positive integer");
	scanf("%d",&n);
	if(n==0)
		printf("0");
	else
		binary(n);
}
