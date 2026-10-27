#include <stdio.h>
int primefactor(int n)
{
	int i = 2;
	if(n==0)
		return 0;
	if(n%i==0)
	{
		printf("%d",i); 	
		n /= i;
		primefactor(n);
	}
	else
		i++; 		
}
int main()
{
	int num;
	printf("Enter a positive integer");
	scanf("%d",&num);
	printf("Prime factors of %d are",num);
	primefactor(num);
}
