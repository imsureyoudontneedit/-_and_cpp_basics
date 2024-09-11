#include <stdio.h>
#include <stdlib.h>


void function(char text[],char text2[])
{
    int i,j,a=0,b;
    char data[7][7]=
    {
        {" ADFGVX"},
        {"Aabcdef"},
        {"Dghijkl"},
        {"Fmnopqr"},
        {"Gstuvwx"},
        {"Vyz1234"},
        {"X567890"}
    };
    for(i=1;i<7;i++)
        for(j=1;j<7;j++){
            for(b=0;text[b];b++)
                if(text[b]==data[i][j])
                {
                    text2[a]=data[0][j];
                    a++;
                    text2[a]=data[i][0];
                    a++;
                    text2[a]=' ';
                    a++;
                    break;
                }
        }
        text2[a]=0;
}

int main()
{
    FILE *f;
    int i;
    char text2[8],text[]={"hell"};
    f=fopen("text.txt","w+");
    function(text,text2);
    for(i=0;text2[i]; i++)
        fputc(text2[i],f);
    return 0;
}

