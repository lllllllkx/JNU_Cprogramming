#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() 
{
    char line[1000];
    printf("«Î ‰»Î“ª––”Ôæ‰£∫\n");
    fgets(line, sizeof(line), stdin);
    line[strcspn(line, "\n")] = '\0';
    
    char* token = strtok(line, " ");
    int flag = 1;
    while (token != NULL) 
    {
        int is_target = 0;
        if (strlen(token) == 3)
        {
            if (tolower(token[0]) == 't' && tolower(token[1]) == 'h' && tolower(token[2]) == 'e')
                is_target = 1;
        }
        if (!is_target) 
        {
            if (!flag) putchar(' ');
            fputs(token, stdout);
            flag = 0;
        }
        token = strtok(NULL, " ");
    }
    putchar('\n');
    return 0;
}
