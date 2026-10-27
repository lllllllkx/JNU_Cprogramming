#include <stdio.h>

int main()
{
	char character;
	
	printf("Enter the character:");
	scanf("%c",&character);
	
	if(character>='A' && character<='Z')
		printf("%c is a capital letter.",character);
	else if(character>='a' && character<='z')
		printf("%c is a small case letter.",character);
	else if(character>='0' && character<='9')
		printf("%c is a digit.",character);
	else
		printf("%c is a special symbol.",character);
		
	return 0;
}
