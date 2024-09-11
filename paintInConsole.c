#include <stdio.h>
#include <stdlib.h>
/*void func(int *a, int *b){
if(*a>15){*a++;};
if(*b==88)*b=101;}
int main()
{
int a=16,b=88;
func(&a,&b);
printf("%d\n%d\n", a,b);
/*printf("%d\n",p);
printf("%d\n",&a);*//*примеры*/
/*/printf("%d\n", *p);
printf("%d\n", a);

    return 0;
}*/


    char f[3][23]={
    {"|                     |"},
    {"| 0=  1=& 2=@ 3=^ 4=# |"},
    {"|                     |"},
    };

void showp(){
    int i,j;
    for(i=0;i<3;i++){
        for(j=0;j<23;j++)
            printf("%c",f[i][j]);
        puts(" ");
    }
}
void showP(int **m){
    int i,j;
    for(i=0;i<20;i++){
        for(j=0;j<65;j++)
            printf("%c",m[i][j]);
        puts(" ");
    }

}

void save(int **m){
    int i,j;
    FILE *f;
    f=fopen("save","wb");
    fwrite(m
           , 600, 1, f);
    fclose(f);
}
void load(int **m){
    int i,j;
    FILE *f;
    f=fopen("save","rb");
    fread(m, 600, 1, f);
    fclose(f);
    }

int main(){
    int cy=5,key,draw,cx=5,g;
    int **m = calloc(20,sizeof(int**)),i,j;
    for(i = 0;i < 20;i++)
        m[i] = calloc(65,sizeof(int**));
    while(key!=27){
        if(kbhit()){
        key=getch();
        system("cls");
         m[cy][cx]=' ';
         m[cy][cx]=draw;
        switch(key){
                case 'w': if(cy>1)cy--; break;
                case 'd': if(cx<63)cx++; break;
                case 'a': if(cx>1)cx--; break;
                case 's': if(cy<18)cy++; break;
                case '0': draw=' '; break;
                case '1': draw='&'; break;
                case '2': draw='@'; break;
                case '3': draw='^'; break;
                case '4': draw='#'; break;
                case 'z': save(m);
                case 'x': load(m);
            }
        m[cy][cx]=219;
        showP(m);
        showp();
        }
    }
    return 0;
}
