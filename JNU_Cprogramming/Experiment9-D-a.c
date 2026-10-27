#include <stdio.h>

void xgets(char *buffer)
{
    char ch;
    int i;
    i = 0;
    while((ch = getchar()) != '\n' && ch != EOF)
    {
        buffer[i] = ch;
        i++;
    }
    buffer[i] = '\0';
}

void xputs(char *str)
{
    int i;
    i = 0;
    while(str[i] != '\0')
    {
        putchar(str[i]);
        i++;
    }
    putchar('\n');
}

int main()
{
    char arr[100];
    printf("Enter a string: ");
    xgets(arr);
    printf("Your input: ");
    xputs(arr);
    return 0;
}
