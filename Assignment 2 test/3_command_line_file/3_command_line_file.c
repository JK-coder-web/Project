#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

int main(int argc,char *argv[])
{
    FILE *sourcefile,*targetfile;
    char ch;

    if(argc!=3)
    {
        printf("Invalid argument");
        exit(1);
    }

    sourcefile=fopen(argv[1],"r");
    targetfile=fopen(argv[2],"a");

    if(sourcefile==NULL || targetfile==NULL)
    {
        printf("File opening error!\n");
    }

    ch=fgetc(sourcefile);
    while(ch!=EOF)
    {
        fputc(ch,targetfile);
        ch=fgetc(sourcefile);
    }

    printf("\nFile copied successful");

    fclose(sourcefile);
    fclose(targetfile);

    getch();
    return 0;
}


