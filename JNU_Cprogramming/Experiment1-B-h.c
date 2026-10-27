#include <stdio.h>

int main()
{
	int integer,digit;
	int cnt = 0;
	int final = 0;
	
	printf("Enter a integer:");
	scanf("%d",&integer);
	while(integer>7)
	{
		digit = integer % 8;
		integer /= 8;
		final += pow(10,cnt) * digit;
		cnt++;  
	} 
	final += pow(10,cnt) * integer;
	printf("0%d",final);
	
	return 0;
}
