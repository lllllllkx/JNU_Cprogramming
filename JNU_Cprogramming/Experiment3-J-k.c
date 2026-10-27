#include <stdio.h>
int gcdivisor(int j,int k)
{
	int m,n;
	while(k>0)
	{
		n = j / k;
		m = k;
		k = j - n * k;
		j = m;
	}
	return m;
}
void main()
{
	int J,K,max,min;
	printf("Enter two integer");
	scanf("%d %d",&J,&K);
	if(J>=K)
	{
		max = J;
		min = K;
	}
	else
	{
		max = K;
		min = J;
	}
	printf("The greatest common divisor is %d",gcdivisor(max,min));
}
