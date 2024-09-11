#include <stdio.h>
#include <stdlib.h>
char Screen[60][60];

void FillMatrix(){
    int i,j;
    for(i=0; i<60; i++)
        for(j=0; j<60; j++)
            Screen[i][j];
}
void DrawRect(int height, int width, int x, int y){
    int i,j;

    for(i=x; i<height+x; i++)
        for(j=y; j<width+y; j++)Screen[i][j]='1';

}
void DrawHoloRect(int height, int width, int x, int y){
    int i,j;
    for(i=x; i<width+x; i++)
        for(j=y; j<height+y; j++)
            if(j==y||j==height+y-1||i==x||i==width+x-1)Screen[j][i]='1';
}
void DrawCircle(int xc,int yc,int radius){
    int x,y,i;
    for(i=0; i<360; i++)
    {
        x=xc+(cos(i)*radius);
        y=yc+(sin(i)*radius);
        Screen[y][x]='1';
    }
}
void DrawFilledCircle(int xc,int yc,int radius){
    int y,x,i,j;
    for(i=0; i<360; i++)
    {
        x=xc+(cos(i)*radius);
        y=yc+(sin(i)*radius);
        Screen[y][x]='1';
    }
    for(j=0; j<radius; j++)
        for(i=0; i<360; i++)
        {
            x=xc+(cos(i)*(radius-j));
            y=yc+(sin(i)*(radius-j));
            Screen[y][x]='1';
        }
}
void GraphMatrix(){
    int i,j;
    for(i=0; i<60; i++)
    {
        for(j=0; j<60; j++)
            printf("%c",Screen[i][j]);
        printf("\n");
    }

}
void DrawCircle2(int R,int xc,int yc){
    int i,j,x,y;
    for(i=0; i<360; i++)
    {
        x=xc+(cos(i)*R);
        y=yc+(sin(i)*R);
        Screen[y][x]='1';
    }

}
void DrawFilledCircle2(int xc,int yc,int R){
    int y,x,i,j;
    int xs=xc-R,ys=yc-R,xh=xc+R,yh=yc+R;
    for(i=0; i<360; i++)
    {
        x=xc+(cos(i)*R);
        y=yc+(sin(i)*R);
        Screen[y][x]='1';
    }
    for(i=xs;i<xh;i++)
        for(j=ys;j<yh;j++)
    {
        if(pow(i-xc,2)+pow(j-yc,2)<pow(R,2))
            Screen[j][i]='1';
    }
}
int main()
{
    FillMatrix();
    /*
    DrawRect(6,14,2,2);
    DrawHoloRect(6,14,22,2);
    DrawFilledCircle(9,32,5);
    DrawCircle(29,32,5);
    */
    DrawFilledCircle2(10,10,9);
    int i,j;
    GraphMatrix();
    return 0;
}









