#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#undef main
int main()
{
    srand(time(0));
    SDL_Window *w=SDL_CreateWindow("title", 100,100,620,480, SDL_WINDOW_SHOWN);
    SDL_Renderer *r=SDL_CreateRenderer(w,-1,SDL_RENDERER_SOFTWARE);
    SDL_SetRenderDrawColor(r,100,100,100,0);
    int i,j=450,k=20;
    for(i=0; i<30; i++)
    {
        SDL_RenderDrawLine(r,k,j,k,0);
        j+=30;
        k+=20;
        SDL_RenderDrawLine(r,k,j,k,20);
        j-=30;
        k+=20;
    }

    SDL_Event event;
    SDL_Rect rect;
    rect.h=10;
    rect.w=10;
    rect.x=610;
    rect.y=470;
    SDL_RenderFillRect(r,&rect);
    rect.x=1;
    rect.y=0;
    int work=1,move=0;
    while(work)
    {
        if(rect.x>=600&&rect.y>=460)
        {
            printf("you win nothing yay\n\n\n\n\n");
            return 0;
        }
        if(rect.x%20==0)
        {
            switch(rect.x)
            {
            case 40:
                if(rect.y>30)
                {
                    rect.w=10;
                    rect.h=10;
                    rect.x=0;
                    rect.y=0;
                }
            case 20:
                if(rect.y<30)
                {
                    rect.w=10;
                    rect.h=10;
                    rect.x=0;
                    rect.y=0;
                }
            }

            break;
        }
        SDL_SetRenderDrawColor(r,0,0,0,0);
        SDL_RenderFillRect(r,&rect);
        if(SDL_PollEvent(&event))
        {
            if(event.type==SDL_KEYDOWN)
                switch(event.key.keysym.sym)
                {
                case SDLK_ESCAPE:
                    work=0;
                    break;
                case SDLK_w: if(rect.y<420){
                                    rect.y-=5;}
                                    break;
                        case SDLK_a: if(rect.x<640){
                                    rect.x-=5;}
                                    break;
                        case SDLK_d: if(rect.x>0){
                                    rect.x+=5;}
                                    break;
                        case SDLK_s: if(rect.y>0){
                                    rect.y-=5;}
                                    break;
                }
            if(event.type==SDL_MOUSEBUTTONDOWN)
            {
                //printf("%d\n",event.button.button);
                move=1;
            }
            if(event.type==SDL_MOUSEBUTTONUP)
            {
                move=0;
            }
            if(event.type==SDL_MOUSEWHEEL)
            {
                //printf("%d\n",event.wheel.y);
                if(event.wheel.y>0)
                {
                    rect.h+=5;
                    rect.w+=5;
                }
                if(event.wheel.y<0)
                {
                    rect.h-=5;
                    rect.w-=5;
                }

            }
            if(event.type==SDL_MOUSEMOTION&&move==1&&rect.x<event.motion.x&&rect.y<event.motion.y&&rect.x+rect.w>event.motion.x&&rect.y+rect.h>event.motion.y)
            {
                rect.x+=event.motion.xrel;
                rect.y+=event.motion.yrel;
            }
            SDL_SetRenderDrawColor(r,200,10,120,0);
            SDL_RenderFillRect(r,&rect);
            SDL_RenderPresent(r);


        }
    }
    return 0;
}
