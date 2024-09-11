#include <stdio.h>
#include <stdlib.h>
char Map[10][240]={//Map for game
    {"00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"},
    {"0                                                                                                                                                                                                                          0                  0"},
    {"0                                                                                                                                                                                                                          0                  0"},
    {"0                                                                                                                                                                                                                          0  BUY!!!          0"},
    {"0                                                                                                                                                                                                                          0  1111  1     111 0"},
    {"0             00000000000000                                                                                                                                                                                               0  1   1 1    1    0"},
    {"0             00000000000000                                             0000000000                                              000000000                                                                                 0  1   1 1    1    0"},
    {"0               0000000000                     00000000000                00000000                    000000000                   0000000                                                                                  0  1   1 1    1    0"},
    {"0               0000000000                      000000000                 00000000                     0000000                    0000000                                                                                  0  1111  1111  111 0"},
    {"00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"},
};

char StatusBar[5][20]={
   {"00000000000000000000"},
   {"0 Name: OmegaSkull 0"},
   {"0 HP: vvvvvvv      0"},
   {"0 Weapon: *******  0"},
   {"00000000000000000000"}
};

int hpx=12;hpy=2,hp=7,bulletvalue=7,xb=17,yb=3; //Player hp and bullet

void hit(){ //- player hp
    hp--;
    if (hp<=0)die();
        StatusBar[hpy][hpx]=' ';
            hpx--;
}
void shootbullet(){ //- player hp
    bulletvalue--;
        StatusBar[yb][xb]=' ';
            bulletvalue--;


}

void die(){ //Death player
    system("cls");
    printf("YOU DIE! TRY AGAIN!");
    _sleep(200000);
}

struct Gamer{
    int x,y;
    int hp;
    int bullet;
    int fall,jump;
    int steps,direction;
    char PlayerName[15];
};


void show(int index){ //draw Map and StatusBar
    int i,j;
    for(i=0; i<5; i++)
    {
        for(j=0; j<20; j++)
            printf("%c",StatusBar[i][j]);
        printf("\n");
    }
    for(i=0; i<10; i++)
    {
        for(j=index; j<index+30; j++)
            printf("%c",Map[i][j]);
        printf("\n");
    }
}
int main(){
    srand(time(0));
    int index=0,key,a=0,b=0,gravity=9,d=0,i,shoot=0,direction;
    struct Gamer G; //Player variables
        G.x=2; //x position
        G.y=7; //y position
        G.fall=0;
    struct Gamer bot; //Bot variable
        bot.x=27; //x position
        bot.y=8; //y position
        bot.hp=10; //bot hp
        bot.steps=0; //bot steps
        bot.direction=0; //bot direction
        char UserName[]="OmegaSkull"; //name of player
        int bullet=1,bx=G.x+1,by=G.y;
    for(i=0;UserName[i];i++)
        G.PlayerName[i]=UserName[i];
    G.PlayerName[i]=0;
    while(key!=27){ //Player and bot function
        Map[bot.y][bot.x]=' ';
        if(bot.x==G.x&&bot.y==G.y){ //if player hit
            hit();
        }
        if(bot.x==bx&&bot.y==by){
            Map[bot.x][bot.y]=' ';
        }
        //Bot steps and direction
        if(Map[bot.y][bot.x+1]=='0'){
                bot.direction=0;
                bot.steps=(rand()%14)+1;
            }
        if(Map[bot.y][bot.x-1]=='0'){
                bot.direction=1;
                bot.steps=(rand()%14)+1;
            }

        if(bot.steps==0){
            bot.direction=rand()%2;
            bot.steps=(rand()%14)+1;
        }
        if(bot.direction==0){
            bot.x--;
            bot.steps--;
        }
        if(bot.direction==1){
            bot.x++;
            bot.steps--;
        }
        Map[G.y][G.x]=' ';
        if(kbhit()){

            key=getch();
            switch(key){ //player control
            case 'd': //x position +
                if(G.x<240-15&&Map[G.y][G.x+1]!='0'&&Map[G.y][G.x+1]!='0')G.x++;direction=key;
                break;
            case 'w': //y position -
                if(Map[G.y+1][G.x]!='0'||Map[G.y+1][G.x]!='0'||Map[G.y-1][G.x]!='0')G.jump=1;direction=key;
                break;
            case ' ':
                shoot=1;break;
            }

        }
        if(shoot==1&&direction=='d'&&xb<10){
        Map[G.y][G.x+xb]=' ';
        xb++;
        Map[G.y][G.x+xb]='*';
        if (Map[yb][xb-1]=='0')
           Map[yb][xb]=' ';
        }else{xb=1;shoot=0;}
        if(G.x-index==15)index++; //player gravity
        if(G.x==index)index--;
        if(G.y<=1){
            G.y++;
        }

        if(Map[G.y+1][G.x]!='0'){
            a++;
            d++;
        }
        else{
            gravity=30;
        }
        if(a>=gravity){
            G.y++;
            a=0;
            gravity-=3;
        }
        if(G.jump==1&&gravity>0&&d>=2){
            G.y--;
            b++;
            gravity-=4;
            d=0;
        }
        if(G.jump==1&&gravity<=0){
            b=0;
            G.jump=0;
            gravity=10;
        }
        if(b>d&&Map[G.y][G.x]=='0'){
            for(b;b>8;b--)
                hit();
            b=0;
        }
        Map[G.y][G.x]=2; //player pic
        Map[bot.y][bot.x]=5; //bot pic
        system("cls");
        show(index);
        _sleep(25);
    }
    return 0;
}
