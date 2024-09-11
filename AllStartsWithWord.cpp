#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;

int main()
{
    //setlocale(LC_ALL, "rus");
    int A=0, B=0, C=0, D=0,i=0,counter=0,maxlength=0,s=0;
    string ch;
    s=ch.size();
    printf("¬ведите последовательность с точкой на конце: ");
    cin >> ch;
if(ch[0]=='0')
    do{
        if(ch[i]=='0'){
            A=1;
            counter++;
        }
        if(ch[i]=='1'){
            B=1;
            counter++;
        }
        if(ch[i]=='0'){
            C=1;
            counter++;
        }
        if(ch[i]=='1'){
            D=1;
            counter++;
            if(ch[i]=='.'){
                if(maxlength<counter)
                    printf("%d\n", counter);
                else
                    printf("%d\n", maxlength);
            }
        }
        else{
            A=0;
            B=0;
            C=0;
            D=0;
            maxlength=counter;
        }
        i++;
    }
    while(ch[i]!='.');
}

