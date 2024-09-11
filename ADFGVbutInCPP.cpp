#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
class ADFGVX{
public:
    char crypt(char *text[]){
        int i=0,j,a=0,b;
        char crypted[80];
        char chiper[8][8]={
            {" ADFGVX"},
            {"Aabcdef"},
            {"Dghijkl"},
            {"Fmnopqr"},
            {"Gstuvwx"},
            {"Vyz1234"},
            {"X567890"}
        };
    for(b=0; text[b]; b++)
        for(i=1; i<7; i++)
            for(j=1; j<7; j++)
            {
                if(*text[b]==chiper[j][i])
                {
                    crypted[a]=chiper[0][i];
                        a++;
                    crypted[a]=chiper[j][0];
                        a++;
                            break;
                }

            }
        crypted[a]=0;
    return crypted[a];
    };
    /*
    char decrypt(char text[]){
        int i=0,j,c=0,non;
        char *crypted[80];
        char chiper[8][8]={
            {" ADFGVX"},
            {"Aabcdef"},
            {"Dghijkl"},
            {"Fmnopqr"},
            {"Gstuvwx"},
            {"Vyz1234"},
            {"X567890"}
        };
    for(non=0; chiper[non]; non++)
        for(i=1; i<7; i++)
            for(j=1; j<7; j++)
            {
                if(chiper[j][i]==text[non])
                {
                    text[c]=chiper[0][i];
                        c++;
                    text[c]=chiper[j][0];
                        c++;
                            break;
                }

            }
            text[c]=0;
    return text[c];
    };
};
*/
};
int main(){
    //int sizem=9000000;
    //char *m=malloc(sizem);
    char crypted[80];
    FILE *f;
    int i;
    char text[]="computeruniverse";
    f=fopen("cipher.txt","w");
    ADFGVX a;
    cout<<a.crypt(text)<<endl;
    return 0;
}
