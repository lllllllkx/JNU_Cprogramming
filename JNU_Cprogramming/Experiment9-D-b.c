#include <stdio.h>

void xgets(char buffer[])
{
    char ch;
    int i;
    i = 0;
    while((ch = getchar()) != '\n' && ch != EOF)
    {
        buffer[i] = ch;
        i = i + 1;
    }
    buffer[i] = '\0';
}

void xputs(char str[])
{
    int i;
    i = 0;
    while(str[i] != '\0')
    {
        putchar(str[i]);
        i = i + 1;
    }
    putchar('\n');
}

int getint()
{
    char buf[50];
    int res, i, sign;
    res = 0;
    sign = 1;
    i = 0;
    xgets(buf);
    if(buf[0] == '-')
    {
        sign = -1;
        i = 1;
    }
    while(buf[i] != '\0')
    {
        res = res * 10 + (buf[i] - '0');
        i = i + 1;
    }
    return res * sign;
}

int main()
{
    int a;
    printf("Enter a numeric string\n");
    a = getint();
    printf("you entered %d", a);
    return 0;
}
