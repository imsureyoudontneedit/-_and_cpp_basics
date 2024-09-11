#include <stdio.h>
#include <stdlib.h>
void BSort(int begin,int end,int *m,int size){
    int i,j,t;
    for(i=begin;i<end;i++){
        for(j=begin;j<end;j++)
            if(m[j]>m[j+1]){
                t=m[j];
                m[j]=m[j+1];
                m[j+1]=t;
            }
         for(i=0;i<size;i++){
            for(j=0;j<m[j];j++)
                printf("#");
            puts(" ");
    }
}

void SSort(int begin,int end,int *m,int size){
    int i,j,t,index,flag;
   for(i=begin;i<end;i++){
        t=m[i];
        index=i;
        flag=0;
    for(j=i+1;j<end;j++)
    if(t>m[j]){
        t=m[j];
        index=j;
        flag=1;
    }
    if(flag){
        m[index]=m[i];
        m[i]=t;
    }
    for(i=0;i<size;i++){
            for(j=0;j<m[j];j++)
                printf("#");
            puts(" ");
        }
   }

}

ISort(int begin,int end,int *m,int size){
    int i,j,buf;
    for(i=begin+1;i<end;i++){
            buf=m[i];
        for(j=i-1;(buf<m[j])&&(j>=0);j--)
                m[j+1]=m[j];
            m[j+1]=buf;
    for(i=0;i<size;i++){
            for(j=0;j<m[j];j++)
                printf("#");
            puts(" ");
        }
    }
}

ShSort(int begin,int end,int *m,int size){
    int i,j,buf,k,vector[]={8,5,3,2,1},offset;
        for(k=0;k<5;k++){
            offset=vector[k];
                for(i=begin+offset;i<end;i++){
                    buf=m[i];
                        for(j=i-offset;(buf<m[j])&&(j>=0);j-=offset)
                            m[j+offset]=m[j];
                        m[j+offset]=buf;
        for(i=0;i<size;i++){
            for(j=0;j<m[j];j++)
                printf("#");
            puts(" ");
        }
                }
        }
}
int main()
{
    srand(time(0));
    int *numbers=malloc(4000);
    int i,key;
    while(key!=27){

        switch(key){
        case '1': ShSort(0,10,numbers);
        case '2': ISort(0,10,numbers);
        case '3': SSort(0,10,numbers);
        case '4': BSort(0,10,numbers);
        case '5':
        }
    }
    for(i=0;i<10;i++)
        numbers[i]=rand()%20;
    puts("\n");
    ShSort(0,10,numbers);
    return 0;
}
