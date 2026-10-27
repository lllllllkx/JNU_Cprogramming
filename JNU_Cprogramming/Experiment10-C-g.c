#include <stdio.h>
#include <string.h>

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

void drawBorder()
{
    int col;
    for(col = 0; col < 80; col++)
    {
        if(col == 0 || col == 79)
        {
            putchar('|');
        }
        else
        {
            putchar('-');
        }
    }
    putchar('\n');
}

int main()
{
    FILE *fp;
    char filename[50], line[78];
    int page, lineCount, spaceFill;
    page = 1;
    printf("Enter source file name: ");
    xgets(filename);
    fp = fopen(filename, "r");
    if(fp == NULL)
    {
        printf("Failed to open target file\n");
        return 1;
    }
    while(feof(fp) == 0)
    {
        printf("\nFile Name: %s | Current Page: %d\n", filename, page);
        drawBorder();
        lineCount = 0;
        while(lineCount < 22 && fgets(line, 78, fp) != NULL)
        {
            printf("|%s", line);
            spaceFill = strlen(line);
            while(spaceFill < 77)
            {
                putchar(' ');
                spaceFill = spaceFill + 1;
            }
            printf("|\n");
            lineCount = lineCount + 1;
        }
        drawBorder();
        printf("Press any key to load next page...");
        getchar();
        page = page + 1;
    }
    fclose(fp);
    return 0;
}
