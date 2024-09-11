#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#undef main
int main()
{
    SDL_Window *w=SDL_CreateWindow("Edward Numbless in space program", 50,25,1000,900, SDL_WINDOW_FULLSCREEN_DESKTOP);
    SDL_Renderer *r=SDL_CreateRenderer(w,-1,SDL_RENDERER_SOFTWARE);
    SDL_Surface *s=SDL_LoadBMP("SpaceShip.bmp");
    SDL_Texture *texture=SDL_CreateTextureFromSurface(r,s);
    SDL_Surface *S=SDL_LoadBMP("$$$XxXVeryC00l2281337shipXxX$$$1.bmp");
    SDL_Texture *Texture=SDL_CreateTextureFromSurface(r,S);
    SDL_Rect rect;
    rect.x=450;
    rect.y=450;
    rect.w=s->w;
    rect.h=s->h;
    SDL_Rect rect2;
    rect2.x=0;
    rect2.y=0;
    rect2.w=10000;
    rect2.h=10000;
    SDL_Rect Bullet;
    Bullet.x=450;
    Bullet.y=4500;
    Bullet.w=64;
    Bullet.h=93;
    SDL_Point point;
    point.x=s->w/2;
    point.y=s->h/2;
    int work=1,i,flag=0,staticangle=0,staticangle2;
    double angle;
    SDL_Event event;
    while(work)
    {
        if(SDL_PollEvent(&event))
        {
            if(event.type==SDL_KEYDOWN)
                switch(event.key.keysym.sym)
                {
                case SDLK_ESCAPE:
                    work=0;
                    break;
                case SDLK_w:
                    staticangle2=(angle*3.14)/180
                    rect.x=rect.x+sin(staticangle2);
                    rect.y=rect.y-cos(staticangle2);
                    break;
                case SDLK_a:
                    angle-=5;
                    break;
                case SDLK_d:
                    angle+=5;
                    break;
                case SDLK_t:
                    flag=1;
                    staticangle=staticangle2;
                    Bullet.x=rect.x;
                    Bullet.y=rect.y;
                    break;

                }
        }
            if(flag){
                Bullet.x=Bullet.x+sin(staticangle)*20;
                Bullet.y=Bullet.y-cos(staticangle)*20;
            }
            if(Bullet.x>=1500||Bullet.y>=1500)flag=0;

        point.x=s->w/2;
        point.y=s->h/2;
        SDL_RenderFillRect(r,&rect2);
        SDL_RenderCopyEx(r,Texture,NULL,&Bullet,staticangle,&point,SDL_FLIP_NONE);
        SDL_RenderCopyEx(r,texture,NULL,&rect,angle,&point,SDL_FLIP_NONE);
        SDL_RenderPresent(r);
    }
    return 0;
}
