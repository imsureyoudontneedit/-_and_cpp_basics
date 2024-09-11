#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *f;
    char message[100], ch;
    int i, key;
    f=fopen("Caeser.txt","w+");
    gets(message);
    printf("Enter number of letters: ");
    scanf("%d", &key);

    for(i=0;message[i]!='\0';++i){
        ch=message[i];

        if(ch>='a'&&ch<='z'){
            ch=ch+key;

            if(ch>'z'){
                ch=ch-'z'+'a'-1;
            }

            message[i]=ch;
        }
        else if(ch>='A'&&ch<='Z'){
            ch=ch+key;

            if(ch>'Z'){
                ch=ch-'Z'+'A'-1;
            }

            message[i]=ch;
        }
    }
    fprintf(f,"%c",message);
    printf("%s", message);

    return 0;
}
