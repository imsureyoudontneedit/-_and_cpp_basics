#include <iostream>
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#undef main
using namespace std;
class BaseGeometry{
protected:
    int x,y,w,h;
public:
    int setSize(int w,int h){
        if(w>=0&&h>=0){
            this->h=h;
            this->w=w;
            return 0;
        }
        return 1;
    };
    int setPosition(int x,int y){
        if(x>=0&&y>=0){
            this->x=x;
            this->y=y;
            return 0;
        }
        return 1;
    };
    int getWidth(){
        return w;
    };
    int getHeight(){
        return h;
    };
    int getX(){
        return x;
    };
    int getY(){
        return y;
    };
};

class Rectangle: public BaseGeometry{
protected:
    int color;
public:
    void SetColor(int color){
        this->color=color;
    }
    int getRed(){
        return color>>16;
    }
    int getBlue(){
        return color>>8&255;
    }
    int getGreen(){
        return color&255;
    }
};

class Screen: public BaseGeometry{
protected:
    SDL_Window *win;
    SDL_Renderer *ren;
    char *title="";
public:
    void setTitle(char *title){
        this->title=title;
    }
    void Init(){
        win=SDL_CreateWindow(title,x,y,w,h,SDL_WINDOW_SHOWN);
        ren=SDL_CreateRenderer(win,-1,SDL_RENDERER_SOFTWARE);

    }
    void DrawRect(Rectangle rect,int mode){
        SDL_Rect r;
        r.h=rect.getHeight();
        r.w=rect.getWidth();
        r.x=rect.getX();
        r.y=rect.getY();
        SDL_SetRenderDrawColor(ren,rect.getRed(),rect.getGreen(),rect.getBlue(),0);
        if(mode==1)
            SDL_RenderFillRect(ren,&r);
        if(mode==0)
            SDL_RenderDrawRect(ren,&r);
    };
    void DrawCircle(int xc,int yc,int radius,int mode){
        SDL_SetRenderDrawColor(ren,255,255,255,0);
        int i,j,xs,ys,xh,yh;
        xs=xc-radius;
        ys=yc-radius;
        xh=xc+radius;
        yh=yc+radius;
        if(mode==0)
            for(i=0; i<360; i++){
                x=xc-(cos(i)*radius);
                y=yc+(sin(i)*radius);
                SDL_RenderDrawPoint(ren,x,y);
            }
        if(mode==1)
            for(i=xs; i<xh; i++)
                for(j=ys; j<yh; j++){
                    if(pow(i-xc,2)+pow(j-yc,2)<pow(radius,2))
                        SDL_RenderDrawPoint(ren,i,j);
                }
    }
    void Draw(){
        SDL_RenderPresent(ren);
        SDL_Delay(10000);
    }
};

int main(){
    Screen S;
    S.setTitle("Base Geometry");
    S.setSize(800,600);
    S.setPosition(50,50);
    S.Init();
    Rectangle Rect;
    Rect.setSize(150,100);
    Rect.setPosition(300,150);
    Rect.SetColor(0xffffff);
    Rectangle Rect2;
    Rect2.setSize(150,100);
    Rect2.setPosition(500,150);
    Rect2.SetColor(0xffffff);
    S.DrawRect(Rect,0);
    S.DrawRect(Rect2,1);
    S.DrawCircle(200,200,50,0);
    S.DrawCircle(50,200,50,1);
    S.Draw();
    return 0;
}
