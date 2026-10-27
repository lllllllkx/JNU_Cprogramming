#include <stdio.h>

void extract_string(char* source, int position, int length) {
    char* ptr = source + position;

    if (length == 0) 
	{
        printf("string: %s\n", ptr);
    }
    else 
	{
        int i;
		for(i = 0; i < length; i++) 
		{
            if (*(ptr + i) == '\0') 
				break; 
            printf("%c", *(ptr + i));
        }
        printf("\n");
    }
}

int main() 
{
    char str[] = "Working with strings is fun";
    int position = 3; 
    int length = 4;   
    extract_string(str, position, length);

    return 0;
}
