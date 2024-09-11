#include <stdio.h>
#include <stdlib.h>
int main(){
    srand(time(0));
    char M[10][15], key, x=2,y=4,xe[]={1,3,5,7,9},ye[]={1,2,3,4,5},p,by,bx,dir;
    int i,j;
//Заполнение матрицы 7-10
        for(i=0;i<10;i++)
            for(j=0;j<15;j++)
                M[i][j]=' ';

        while(key!=27){
//Враги 13-19 строка
            M[y][x]='#';
            M[ye[1]][xe[1]]='!';
            M[ye[2]][xe[2]]='!';
            M[ye[3]][xe[3]]='!';
            M[ye[4]][xe[4]]='!';
            M[ye[5]][xe[5]]='!';

//Проверка на смерть 21-25
        if((x==xe[1])&&(y==ye[1])||(x==xe[2])&&(y==ye[2])||(x==xe[3])&&(y==ye[3])||(x==xe[4])&&(y==ye[4])||(x==xe[5])&&(y==ye[5])){
            system("cls");
            printf("You DIE!");
                break;
        }
//Отборжение матрицы 27-31
        for(i=0;i<10;i++){
            for(j=0;j<15;j++)
                printf("%c",M[i][j]);
            printf("\n");
        }
//Замещение символов за врагами и персонажем 33-40
    M[ye[1]][xe[1]]=' ';
    M[ye[2]][xe[2]]=' ';
    M[ye[3]][xe[3]]=' ';
    M[ye[4]][xe[4]]=' ';
    M[ye[5]][xe[5]]=' ';
    M[y][x]=' ';
    M[by][bx]=' ';
            system("cls");

//Движение персонажа и стрельба 43-
        if(kbhit()){
            key=getch();
                switch(key){
                    case'w':
                        if(y>0)y--;dir=key;break;
                    case's':
                        if(y<10)y++;dir=key;break;
                    case'a':
                        if(x>0)x--;dir=key;break;
                    case'd':
                        if(x<15)x++;dir=key;break;

                    case' ':
                        switch(dir){
                            case'w':
                                for(by==y-1;y>0;y--)
                                        M[by][x]='*';
                                    break;

                            case's':
                                for(by==y+1;y<15;y++)
                                        M[by][x]='*';
                                    break;

                            case'a':
                                for(bx==x-1;x>0;x--)
                                        M[y][bx]='*';
                                    break;

                            case'd':
                                for(bx==x+1;x>10;x++)
                                        M[y][bx]='*';
                                    break;


                        }
                    }
                }
        for(i=0;i<6;i++){
            p=rand()%56;
                switch(p){
                    case 0:
                        if(ye[i]>0)ye[i]--;
                            break;

                    case 1:
                        if(ye[i]<14)ye[i]++;
                            break;

                    case 2:
                        if(xe[i]>0)xe[i]--;
                            break;

                    case 3:
                        if(xe[i]<9)xe[i]++;
                            break;

                }
            }
        }
                    return 0;
}
