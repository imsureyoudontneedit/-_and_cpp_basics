#include <stdio.h>
#include <stdlib.h>
void func1(char text[],int flag;){
    char data[2][25]={
                    {"abcdefghijklmopqrstuvwxyz"},
                    {"N_\(-)/?][M{><}L891@%$C0R"},
    };
        int indexA=0,indexB=1,i,j,flag;
        if(flag==1){
            indexA=1;
            indexB=0;
        }
        else{
            indexA=0;
            indexB=1;
        }
            for(i=0;text[i];i++)
                for(j=0;data[indexA];j++){
                    if(text[i]==data[indexA][i]){
                        text[i]=data[indexB][j];
                        break;
                    }
                }
}

int main()
{
    char text[]="GGG";
    func1(text,1);
    puts(text);
    return 0;
}











