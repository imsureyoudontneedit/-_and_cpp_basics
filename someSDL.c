#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#undef main
int main()
{
    SDL_Window *w=SDL_CreateWindow("Edward Numbless in space program", 50,25,1000,900, SDL_WINDOW_FULLSCREEN_DESKTOP);
    SDL_Renderer *r=SDL_CreateRenderer(w,-1,SDL_RENDERER_SOFTWARE);
    SDL_Surface *img=SDL_LoadBMP("pic.bmp");
    int x=5,y=9,d=img->format->BytesPerPixel,i,j,work=1;
    SDL_Event event;
    SDL_Rect rect;
    rect.x=0;
    rect.y=0;
    rect.w=img->w;
    rect.h=img->h;
    SDL_Point point;
    point.x=img->w/2;
    point.y=img->h/2;
    char *p=img->pixels+(img->pitch*y)+(x*d);
        while(work){
        if(SDL_PollEvent(&event))
        {
            if(event.type==SDL_KEYDOWN)
                switch(event.key.keysym.sym){
                case SDLK_ESCAPE:
                    work=0;
                    break;
                case SDLK_1:
                        break;
                case SDLK_2:
                    for(i=0;i<img->w;i++)
                            for(j=0;j<img->h;j++){
                                if(*(int*)p!=0x00ff00){
                                        SDL_SetRenderDrawColor(r,0,p[2],0,0);
                                        SDL_RenderDrawPoint(r,j,i);

                                    }
                                    p+=d;
                                }
                                break;
                case SDLK_3:
                    for(i=0;i<img->w;i++)
                            for(j=0;j<img->h;j++){
                                if(*(int*)p!=0x0000ff){
                                        SDL_SetRenderDrawColor(r,0,0,p[2],0);
                                        SDL_RenderDrawPoint(r,j,i);

                                    }
                                    p+=d;
                                }
                                break;
                case SDLK_4:
                        for(i=0;i<img->w;i++)
                            for(j=0;j<img->h;j++){
                                if(*(int*)p!=0xff0000&&*(int*)p!=0x00ff00){
                                        SDL_SetRenderDrawColor(r,p[2],p[2],0,0);
                                        SDL_RenderDrawPoint(r,j,i);

                                    }
                                    p+=d;
                                }
                                break;
                case SDLK_5:
                    for(i=0;i<img->w;i++)
                            for(j=0;j<img->h;j++){
                                if(*(int*)p!=0x0000ff&&*(int*)p!=0x00ff00){
                                        SDL_SetRenderDrawColor(r,0,p[2],p[2],0);
                                        SDL_RenderDrawPoint(r,j,i);

                                    }
                                    p+=d;
                                }
                                break;
                case SDLK_6:
                    for(i=0;i<img->w;i++)
                            for(j=0;j<img->h;j++){
                                if(*(int*)p!=0xff0000&&*(int*)p!=0x0000ff){
                                        SDL_SetRenderDrawColor(r,p[2],0,p[2],0);
                                        SDL_RenderDrawPoint(r,j,i);

                                    }
                                    p+=d;
                                }
                                break;
                case SDLK_7:
                        for(i=0;i<img->w;i++)
                            for(j=0;j<img->h;j++){
                                if(*(int*)p!=0xff0000^*(int*)p!=0x0000ff){
                                        SDL_SetRenderDrawColor(r,p[2],0,p[2],0);
                                        SDL_RenderDrawPoint(r,j,i);

                                    }
                                    p+=d;
                                }
                                break;
                case SDLK_8:
                    for(i=0;i<img->w;i++)
                            for(j=0;j<img->h;j++){
                                if(*(int*)p!=0x00ff00^*(int*)p!=0x0000ff^*(int*)p!=0xff0000){
                                        SDL_SetRenderDrawColor(r,p[2],p[1],p[0],0);
                                        SDL_RenderDrawPoint(r,j,i);

                                    }
                                    p+=d;
                                }
                                break;
                case SDLK_9:
                    for(i=0;i<img->w;i++)
                            for(j=0;j<img->h;j++){
                                if(*(int*)p!=0xff0000^*(int*)p!=0x00ff00){
                                        SDL_SetRenderDrawColor(r,p[2],p[21],0,0);
                                        SDL_RenderDrawPoint(r,j,i);
                                    }
                                    p+=d;
                                }
                                break;
        }

            SDL_RenderPresent(r);
        }
        }
    return 0;
}
