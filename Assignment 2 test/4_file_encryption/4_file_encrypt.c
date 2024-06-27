#include<stdio.h>
#include<stdlib.h>
#define MAX_LENGTH 1024

void encrypt_text(char* text,int key)
{
    for(int i=0;text[i]!='\0';i++)
    {
        char letter=text[i];

        if(letter>='a' && letter<='z')
        {
            letter=((letter - 'a' + key)%26)+'a';
        }
        else if(letter>='A' && letter<='Z')
        {
            letter=((letter - 'A' + key)%26)+'A';
        }
        text[i]=letter;
    }
}

int main()
{
    int key;
    char text[MAX_LENGTH];
    FILE *input_file, *output_file;

    printf("Enter a key: ");
    scanf("%d",&key);

    input_file=fopen("input.txt","r");
    if(input_file==NULL)
    {
        printf("Could not open input file.\n");
        return 1;
    }

    fgets(text,MAX_LENGTH,input_file);
    fclose(input_file);

    encrypt_text(text,key);

    output_file=fopen("output.txt","w");
    if(output_file==NULL)
    {
        printf("Could not open output file.\n");
        return 1;
    }

    fputs(text,output_file);
    fclose(output_file);

    printf("Encryption successful.\n");
    return 0;
}

