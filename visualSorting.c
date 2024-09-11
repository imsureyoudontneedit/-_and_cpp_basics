#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#undef main

void SortSDLColumns(int count, int numbers[],SDL_Renderer *r)
{
    int i,j,t,l,index,flag;
    SDL_Rect rect;
    SDL_Rect rect2;
    rect2.x=0;
    rect2.y=0;
    rect2.w=10000;
    rect2.h=10000;

    for(i=0; i<count; i++)
    {
        t=numbers[i];
        index=i;
        flag=0;
        for(j=i+1; j<count; j++)
            if(t>numbers[j])
            {
                t=numbers[j];
                index=j;
                flag=1;
            }
        if(flag)
        {
            numbers[index]=numbers[i];
            numbers[i]=t;
        }

        rect.x=0;
        rect.w=800/count;
        int a;
                    SDL_SetRenderDrawColor(r,0,0,0,0);
            SDL_RenderFillRect(r,&rect2);
        for(a=0; a<count; a++)
        {   SDL_SetRenderDrawColor(r,225,225,255,0);
            if(a==index)SDL_SetRenderDrawColor(r,0,255,0,0);
            if(a==i)SDL_SetRenderDrawColor(r,0,255,0,0);
            rect.y=800-numbers[a];
            rect.h=numbers[a];


            SDL_RenderFillRect(r,&rect);
            rect.x+=rect.w;

        }
            SDL_RenderPresent(r);
            SDL_Delay(1000);
    }


}
int main()
{
    SDL_Window *w=SDL_CreateWindow("title",10,10,800,800,SDL_WINDOW_SHOWN);
    SDL_Renderer *r=SDL_CreateRenderer(w,-1,SDL_RENDERER_SOFTWARE);
    srand(time(0));
    int y=100;
    int numbers[y],i;
    for(i=0; i<y; i++)
    {
        numbers[i]=rand()%80+1;
        numbers[i]*=10;
    }
    SortSDLColumns(y,numbers,r);




    return 0;
}
