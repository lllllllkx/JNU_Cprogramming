#include <stdio.h>
#include <math.h>

int main()
{
	int a,b,c;
	int num = 1;
	int sum = 0;
	printf("Armstrong numbers:");
	
	while(num<=500)
	{
		a = num / 100;
		b = (num - a * 100) / 10;
		c = num % 100 - b * 10;
		sum = pow(a,3) + pow(b,3) + pow(c,3);
		if(num==sum)
			printf("%d ",num);
		num++;
	}
	
	return 0;
}
