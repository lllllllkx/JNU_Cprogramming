#include <stdio.h>
int binary(int n)
{
	int i = 0;
	int a[32];
	while(n>0)
	{
		a[i] = n % 2;
		n /= 2;
		i ++;
	}
	for(i=i-1;i>=0;i--)
	{
		printf("%d",a[i]);
	}
}
void main()
{
	int num;
	printf("Enter an integer");
	scanf("%d",&num);
	binary(num);
}
