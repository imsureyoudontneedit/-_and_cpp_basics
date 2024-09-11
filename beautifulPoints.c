#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#undef main

struct Point{
SDL_Rect rect;
int color;
int weight;
};

int main()
{
    SDL_Window *w=SDL_CreateWindow("title",10,10,800,600,SDL_WINDOW_SHOWN);
    SDL_Renderer *r=SDL_CreateRenderer(w,-1,SDL_RENDERER_SOFTWARE);
    srand(time(0));
    int i,j,st=10000;
struct Point p[st];
for(i=0;i<st;i++){
p[i].rect.x=rand()%255;
p[i].rect.y=rand()%255;
p[i].weight=p[i].rect.x+p[i].rect.y;
SDL_SetRenderDrawColor(r,p[i].rect.x,p[i].rect.y,p[i].weight,0);
SDL_RenderDrawPoint(r,p[i].rect.x,p[i].rect.y);
}
SDL_RenderPresent(r);
SDL_Delay(100000);
return 0;
}
