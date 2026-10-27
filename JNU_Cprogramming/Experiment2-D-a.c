#include <stdio.h>

int factional(int n)
{
	int i = 1;
	int fac = 1;
	for(i=1;i<=n;i++)
	{
		fac *= i;
	}
	
	return fac;
} 

main()
{
	int x;
	printf("Enter an integer:\n");
	scanf("%d",&x);
	printf("The factional value of %d is %d",x,factional(x));
}
