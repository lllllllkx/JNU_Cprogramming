#include <stdio.h>

int main()
{
	unsigned char ascii;
	ascii = 0;
	printf("ASCII\tCharacter\n");
	while(ascii <= 255)
	{
		printf("%d\t%c\n",ascii,ascii);
		if(ascii == 255)
		{
			break;
		}
		ascii++;
	}
	return 0;
}
