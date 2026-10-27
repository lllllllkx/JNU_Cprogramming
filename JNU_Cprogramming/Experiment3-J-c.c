#include <stdio.h>

int fibonacci(int n)
{
	if(n<=2)
		return 1;
	else
		return fibonacci(n-1)+fibonacci(n-2);
}
void main()
{
	int n = 25;
	int i;
	for(i=1;i<=n;i++)
	{
		printf("%d\n",fibonacci(i));
	}	
}
