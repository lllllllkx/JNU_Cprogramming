#include <stdio.h>
#include <stdlib.h>

int main() 
{
    char str[] = "124";
    int num;

    num = atoi(str);

    printf("string '%s' is converted to integer: %d\n", str, num);

    return 0;
}
