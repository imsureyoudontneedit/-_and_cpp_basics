#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#undef main
int main()
{
    srand(time(0));
    SDL_Window *w = SDL_CreateWindow("Terraria",0,0,1280,1024, SDL_WINDOW_SHOWN);
    SDL_Renderer *r = SDL_CreateRenderer(w,-1,SDL_RENDERER_SOFTWARE);
    SDL_Event event;
    SDL_Rect(rect);
    rect.x=320;
    rect.y=210;
    rect.h=15;
    rect.w=15;
    int work=1,flag=0,red,blue,green;
        while(work){
            if(SDL_PollEvent(&event)){
                SDL_SetRenderDrawColor(r,0,0,0,0);

                    if(event.type==SDL_KEYDOWN)
                        switch(event.key.keysym.sym){
                        case SDLK_ESCAPE: work=0;break;
                        case SDLK_w: if(rect.y<1024){
                                    rect.y-=5;}
                                    break;
                        case SDLK_a: if(rect.x<1280){
                                    rect.x-=5;}
                                    break;
                        case SDLK_d: if(rect.x>0){
                                    rect.x+=5;}
                                    break;
                        case SDLK_s: if(rect.y>0){
                                    rect.y+=5;}
                                    break;
                        case SDLK_1: red=rand()%255;
                                     blue=rand()%255;
                                     green=rand()%255;
                        }
                    if(event.type==SDL_MOUSEBUTTONUP)
                        flag=0;
                    if(event.type==SDL_MOUSEBUTTONDOWN)
                        flag=1;
                        if(event.type==SDL_MOUSEMOTION&&flag==1)
                            if(rect.x<1280||rect.x>0||rect.y<1024||rect.y>0){
                                    rect.x+=event.motion.xrel;
                                    rect.y+=event.motion.yrel;
                        }
                    if(event.type==SDL_MOUSEWHEEL){
                       if(event.wheel.y>=1){
                        rect.h+=2;
                        rect.w+=2;
                       }
                       if(event.wheel.y<=-1){
                        rect.h-=2;
                        rect.w-=2;
                       }
                    }
                SDL_SetRenderDrawColor(r,red,blue,green,0);
                SDL_RenderFillRect(r,&rect);
                SDL_RenderPresent(r);
            }
        }
    return 0;
}
