#include <stdio.h>

int main()
{
	int matchstick = 21;
	int user,computer;
	printf("There are 21 matchsticks.\n");
	printf("You can pick 1,2,3,or 4 matchsticks.\n");
	printf("Whoever picked up the last matchsticks loses the game.\n");
	
	while(matchstick>1)
	{
		printf("Enter the number of matchsticks you picked:\n");
		scanf("%d",&user);
		computer = 5 - user;
		matchstick -= 5;
		printf("There are %d matchsticks now.\n",matchstick);
	}
	printf("You lose!");
	
	return 0;
}
