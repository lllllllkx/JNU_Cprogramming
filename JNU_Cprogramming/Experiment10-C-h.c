#include <stdio.h>

void offsetCipher(FILE *in, FILE *out, int offset, int mode)
{
    char ch;
    while((ch = fgetc(in)) != EOF)
    {
        if(mode == 1)
            fputc(ch + offset, out);
        else
            fputc(ch - offset, out);
    }
}

int main()
{
    FILE *fin, *fout;
    char inName[30], outName[30];
    int op, offset;
    printf("1=Encrypt Offset | 2=Decrypt Offset\nChoose: ");
    scanf("%d",&op);
    printf("Input file name: ");
    scanf("%s",inName);
    printf("Output file name: ");
    scanf("%s",outName);
    printf("Set offset value: ");
    scanf("%d",&offset);
    fin = fopen(inName,"rb");
    fout = fopen(outName,"wb");
    offsetCipher(fin,fout,offset,op);
    fclose(fin);
    fclose(fout);
    printf("Operation finished\n");
    return 0;
}
