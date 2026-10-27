#include <stdio.h>

int main()
{
	int i = 0;
	int num;
	int n = 0;
	int j = 1;
	
	
	while(i<=4)
	{	printf("Enter your option:\n");
		printf("1:Factorial of a number.\n");
		printf("2:Prime or not.\n");
		printf("3:Odd or even.\n");
		printf("4:Exit.\n");
		scanf("%d",&i);
		switch(i)
		{
			case 1:
				printf("Factorial of a number.\n");
				printf("Enter a number:");
				scanf("%d",&num);
				while(num>0)
				{
					j *= num;
					num --;
				}
				printf("n!=%d\n",j);
				j = 1;
				break;
			case 2:
				printf("Prime or not.\n");
				printf("Enter a number:\n");
				scanf("%d",&num);
				j = 2;
				while(j<num)
				{
					n = num % j;
					if(n!=0)
						j++;
					else
						goto out;	
				}
				out:
				if(j<num)
					printf("%d is not prime\n",num);
				else
					printf("%d is prime\n",num);
				break;
			case 3:
				printf("Odd or even.\n");
				printf("Enter a number:\n");
				scanf("%d",&num);
				if(num%2==0)
					printf("%d is even.\n",num);
				else
					printf("%d is odd.\n",num);
				break;
			case 4:
				printf("Exit.\n");
				i ++;
				break;
		}
	}
	
	return 0;
}
