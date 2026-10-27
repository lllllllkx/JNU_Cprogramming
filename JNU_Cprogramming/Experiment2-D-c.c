#include <stdio.h>
#include <string.h>

void Roman(int n,char *roman)
{
	int value[] = {1000,500,100,50,10,5,1};
	char *symbols[] = {"m","d","c","l","x","v","i"};
	roman[0]='\0';
	int i;
	for(i=0;i<7;i++)
	{
		while(n>=value[i])
		{
			strcat(roman,symbols[i]);
			n -= value[i];
		}	
	}
}

int main()
{
	int year;
	char roman[20];
	printf("Enter a year\n");
	scanf("%d",&year);
	Roman(year,roman);
	printf("Roman equivalent of %d is %s",year,roman); 
}

