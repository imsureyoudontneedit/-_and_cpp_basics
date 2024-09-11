#include <stdio.h>
#include <stdlib.h>
void Hexcimal();

void Hexcimal(){
            char N[]="F94A";
            char Convernter[]="0123456789ABCDEF";
            int bottom=16,len,r=0,p,i,j;
    for(len=0;N[len];len++);
        p=len-1;
    for(i=0;i<len;i++){
        for(j=0;j<bottom;j++)
            if(N[i]==Convernter[j])break;
                r+=(j*pow(bottom,p));
                    p--;
}
        printf("%d",r);


}

int main()
{
        Hexcimal();
        return 0;
}
