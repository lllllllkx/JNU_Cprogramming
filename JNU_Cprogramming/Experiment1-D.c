#include <stdio.h>

int main()
{
	int classnum,num,grace;
	printf("Enter your class and the number of subjects you failed in:\n");
	scanf("%d %d",&classnum,&num);
	switch(classnum)
	{
		case 1 :
			if(num<=3)
				grace = 5;
			else
				grace = 0;
		break;
		case 2 :
			if(num<=2)
				grace = 4;
			else
				grace = 0;
			break;
		case 3 :
			if(num<=1)
				grace = 5;
			else 
				grace = 0;
			break;
	}
	printf("Your grace is of %d marks per subject.\n",grace);
	
	return 0;
}
