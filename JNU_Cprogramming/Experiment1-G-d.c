#include <stdio.h>

int main()
{
	int days;
	int fine = 0;
	printf("Enter the number of days:");
	scanf("%d",&days);
	
	if(days<=5)
	{
		fine = 50;
		printf("Your fine is %d paise.",fine);
	}
		
	else if(days<=10)
	{
		fine = 1;
		printf("Your fine is %d rupees.",fine);
	}	
	else if(days<30)
	{
		fine = 5;
		printf("Your fine is %d rupees.",fine);
	}
	else
		printf("Your membership will be cancelled.");
	
	return 0;
} 
