#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char fullName[100];
    char nameParts[10][50];
    int partNum = 0;
	int i;
	
    printf("Please enter your full English name separated by spaces: ");
    fgets(fullName, sizeof(fullName), stdin);
    fullName[strcspn(fullName, "\n")] = '\0';

    char *p = strtok(fullName, " ");
    while (p != NULL)
    {
        strcpy(nameParts[partNum], p);
        partNum++;
        p = strtok(NULL, " ");
    }

    if (partNum == 0)
    {
        printf("Input cannot be empty!\n");
        return 1;
    }

    for (i = 0; i < partNum - 1; i++)
    {
        printf("%c. ", toupper(nameParts[i][0]));
    }

    char *lastName = nameParts[partNum - 1];
    printf("%c", toupper(lastName[0]));
    for (i = 1; lastName[i] != '\0'; i++)
    {
        printf("%c", lastName[i]);
    }

    printf("\n");
    return 0;
}
