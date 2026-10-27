#include <stdio.h>

int main()
{
	int hardness,tensile_strenth;
	double carbon_content;
	int grade = 0;
	printf("Enter the value of hardness,carbon_content,tensile_strenth of the steel:\n");
	scanf("%d %lf %d",&hardness,&carbon_content,&tensile_strenth);
	
	if (hardness>50)
	{
		if(carbon_content<0.7)
		{
			if(tensile_strenth>5600)
			{
				grade = 10;
			}
			else
			{
				grade = 9;
			}
		}
		else if(tensile_strenth>5600)
		{
			grade = 7;
		}
		else
			grade = 6;
	}
	else if(carbon_content<0.7)
	{
		if(tensile_strenth>5600)
		{
			grade = 8;
		}
		else
			grade = 6;
	}
	else if(tensile_strenth>5600)
		grade = 6;
	else
		grade = 5;
		
	printf("The grade of steel is %d\n",grade);
	
	return 0;
}
