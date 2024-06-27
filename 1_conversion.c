#include<stdio.h>
#define SIZE 100

int input_validate(char ch_bin[]);
int bin_to_deci(char binary[]);
void deci_to_hexa(int dec);
void deci_to_octal(int dec);
int main()
{
    char bin[SIZE];

    printf("Enter the binary number(1-0): ");
    gets(bin);
    int input=input_validate(bin);
    if(input==1)
    {
        int deci_num=bin_to_deci(bin);
        printf("Decimal number is %d\n",deci_num);
        deci_to_hexa(deci_num);
        deci_to_octal(deci_num);
    }
    else
    {
        printf("Your entered number is invalid!\n");
    }
    return 0;
}
int input_validate(char ch_bin[])
{
    int i=0;
    while(ch_bin[i]!='\0')
    {
        if(ch_bin[i]=='0' || ch_bin[i]=='1')
        {
            return 1;
        }
        i++;
    }
    return -1;
}
int bin_to_deci(char binary[])
{
    int i=0;
    int number=0;
    int decimal=0;
    while(binary[i]!='\0')
    {
        number=binary[i]-48;
        decimal=decimal*2+number;
        i++;
    }
    return decimal;
}
void deci_to_hexa(int dec)
{
    int hexa[SIZE];
    int x=0;
    int y=0;

    while(dec != 0)
    {
        hexa[x]=dec%16;
        dec=dec/16;
        x++;
    }

    printf("Hexadecimal number is ");
    for(y=x-1; y>=0; y--)
    {
        if(hexa[y]>9)
        {
            printf("%c",hexa[y]+55);
        }
        else
        {
            printf("%d",hexa[y]);
        }
    }
    printf("\n");
}
void deci_to_octal(int dec)
{
    int octal[SIZE];
    int x=0;
    int y=0;

    while(dec != 0)
    {
        octal[x]=dec%8;
        dec=dec/8;
        x++;
    }

    printf("Octal number is ");
    for(y=x-1; y>=0; y--)
    {
        printf("%d",octal[y]);

    }
    printf("\n");
}
