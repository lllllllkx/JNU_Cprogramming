#include <stdio.h>
#include <math.h>

double factorial(int n)
{
	if(n==0||n==1)
		return 1;
	return n * factorial(n-1);
} 
double sinseries(double x,int terms)
{
	double sum = 0.0;
	int i;
	for(i=0;i<terms;i++)
	{
		int power = 2 * i + 1;
		double terms = pow(-1,i) * pow(x,power) / factorial(power);
		sum += terms;
		return sum;
	}
}
void main()
{
	double x;
	printf("Enter x");
	scanf("%lf",&x);
	printf("sin(x)¡Ö%.5g\n",sinseries(x,10));
}
