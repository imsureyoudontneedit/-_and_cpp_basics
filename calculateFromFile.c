#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *f=fopen("ds.txt","r");
    int buf,i;
    char numbers[10];
    fgets(numbers,10,f);
    char math[14]={"012456789+-*:"};
    for(len=0;numbers[len];len++)
        for(i=0;i<len;i++){
            for(j=0;j<14;j++)
                if(numbers[i]==math[j])break;
    printf("%s", numbers);
    return 0;
}
