#include <stdio.h>
#include <stdlib.h>
void Control();

void Control(int y,int x, int bullet,){
            case 'w':
                if (y>0)y--;
                break;
            case 's':
                if (y<24)y++;
                break;
            case 'a':
                if (x>0)x--;
                break;
            case 'd':
                if (x<24)x++;
                break;
            case 75:
                bullet=1;
                M[bulletx][bullety]=' ';
                bulletx=y;
                bullety=x;
                break;
            case 72:
                bullet=2;
                M[bulletx][bullety]=' ';
                bulletx=y;
                bullety=x;
                break;
            case 77:
                bullet=3;
                M[bulletx][bullety]=' ';
                bulletx=y;
                bullety=x;
                break;
            case 80:
                bullet=4;
                M[bulletx][bullety]=' ';
                bulletx=y;
                bullety=x;
                break;
}
int main()
{
    srand(time(0));
    int i,j,timer=0,timer2=0,clean=0,enhp[19];
    char M[25][25],key,bullet,bulletx=0,bullety=0,x=1,y=1,enalive[]={1,1,1,1,1},ywin=0,xwin=0,randmove,lose,xenemy[]= {22,25,24,18,13,1,1,1,1,17,18,9,19,20,6,23,8,17,13},yenemy[]= {1,2,3,4,8,14,5,7,22,12,5,16,24,9,10,6,8,10,6};
    for(i=0; i<25; i++)
        for(j=0; j<25; j++)
            M[i][j]=' ';
    for(i=0;i<19;i++)
        enhp[i]=100;
    ywin=rand()%25;
    xwin=rand()%25;
    while (key!=27)
    {
        if(clean==1)
        M[bulletx][bullety]=253;

        system("cls");
        M[y][x]='#';
        M[ywin][xwin]='0';
        for(i=0; i<25; i++)
        {
            for(j=0; j<25; j++)
                printf("%c",M[i][j]);
            printf("\n");
        }
        M[y][x]=' ';


        for(i=0; i<19; i++)
        {

            randmove=rand()%5;
            M[yenemy[i]][xenemy[i]]=' ';
            switch(randmove)
            {
            case 1:
                if (yenemy[i]>1&&enalive[i]==1)yenemy[i]--;
                break;
            case 2:
                if (yenemy[i]<24&&enalive[i]==1)yenemy[i]++;
                break;
            case 3:
                if (xenemy[i]>1&&enalive[i]==1)xenemy[i]--;
                break;
            case 4:
                if (xenemy[i]<24&&enalive[i]==1)xenemy[i]++;
                break;
            }
            M[yenemy[i]][xenemy[i]]='X';

            if (y==yenemy[i]&&x==xenemy[i]&&enalive[i]==1)
            {
                lose=1;
                break;

            }
            if (bulletx==yenemy[i]&&bullety==xenemy[i])
            {
                bullet=0;
                enhp[i]-=50;
                if(enhp[i]<=0)
                {enalive[i]=0;
                yenemy[i]=0;
                xenemy[i]=0;
                }


            }

        }
        if(lose==1)
        {

            printf("YOU DIED!\n");
            printf("YOU SURVIVED %d",timer);
            _sleep(1000);
            break;
        }

        if(kbhit())
        {
            key=getch();
            printf("%d",key);
            switch(key)
            {
                Control();
            }

        }
        timer++;
        if(y==ywin&&x==xwin)
        {
            printf("YOU WIN!!!! YOU WIN NOTHING!!! WOOHOO!!!");
            _sleep(1000);
            break;
        }
        switch(bullet)
        {
            case 1:

            M[bulletx][bullety]=' ';
            if (bullety>0)
            {
                clean=1;
                bullety--;
            }
            else clean=0;
            break;
            case 2:

            M[bulletx][bullety]=' ';
            if (bulletx>0)
                        {
                clean=1;
                bulletx--;
            }
            else clean=0;
            break;
            case 3:

            M[bulletx][bullety]=' ';
            if (bullety<24)
            {
                clean=1;
                bullety++;
            }
            else clean=0;
            break;
            case 4:
            M[bulletx][bullety]=' ';
            if (bulletx<24)
            {
                clean=1;
                bulletx++;
            }
            else clean=0;

            break;
            case 0:
                clean=0;
        }
        M[0][0]=' ';


    }
    return 0;
}





