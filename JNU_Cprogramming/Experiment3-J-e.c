#include <stdio.h>
int sum(int n)
{
	if(n==0)
		return 0;
	else
		return n+sum(n-1); 
} 
void main()
{
	int n = 25;
	printf("%d",sum(n));
}
