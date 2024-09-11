#include <cstdlib>
#include <iostream>
#include <math.h>
#include <stdio.h>

using namespace std;
int strLength(char text)
{
    int length = 0;
    while(text++) ++length;
    return length;
}
//Operation with circle
class Circle{
private:
    int x=7,y=5;
    float p=3.14;
public:
    int calcSquare(int r){
        float s;
        s = this->p*r*r;
        cout<<"Square = "<<s<<endl;
        printf("\n");
    }
    int pointin(int x,int y,int r){
        if(pow(this->x-x,2)+pow(this->y-y,2)<pow(r,2)){
            cout<<"Point does Enter"<<endl;
            printf("\n");}
        else{
            cout<<"Point doesn't enter"<<endl;
            printf("\n");}
    }
};
//Work with text
class Text{
public:
    int symbolsValues(char text[],int length){
        int i,symbols=0;
        char *space=" ";
        for(i=0;i<length;i++){
            if(text[i]!=*space)
                symbols++;
        }
        cout<<"Values of symbols: "<<symbols<<endl;
        printf("\n");
    return 0;
    };
    int wordsValues(char text[],int length){
        int i,space=0;
        for(i=0;i<length;i++){
            if(text[i]==' ')
                space=space+1;
        }
        cout<<"Values of words: "<<space+1<<endl;
        printf("\n");
        printf("\n");
    };
};
//From string to number
class Number{
    public:
   int stringtonumber(char N[]){
        char Convernter[]="0123456789ABCDEF";
            int bottom=16,len,r=0,p,i,j;
    for(len=0;N[len];len++);
        p=len-1;
    for(i=0;i<len;i++){
        for(j=0;j<bottom;j++)
            if(N[i]==Convernter[j])break;
                r+=(j*pow(bottom,p));
                    p--;
}
        cout<<"Number: "<<r<<endl;
        printf("\n");
    }
};
class videoMemory{
    public:
        int videoSize(int w,int h,int deep,int timemin,int fps){
            float videobit,videobyte,videom,timesec,videog;
            timesec=timemin*60;
            videobit=w*h*deep*fps*timesec;
            videobyte=videobit/8;
            videom=videobyte/1024/1024;
            videog=videom/1024;
            cout<<"Video size in GByte: "<<videog<<endl;
            printf("\n");
            cout<<"Video size in MByte: "<<videom<<endl;
            printf("\n");        }
};
int main(){
    int length=4;
    char number[]="F94A";
    char text[]="Lorem ipsum dolor sit amet, consectetur adipiscing elit. Etiam iaculis metus sed dolor fringilla, at fermentum erat molestie. Sed interdum dui ac risus accumsan, sit.";
    length=strLength(*text);
    puts("Circle\n");
    Circle c;
    c.calcSquare(10);
    c.pointin(4,6,10);
    puts("\n");
    puts("Text\n");
    Text t;
    t.symbolsValues(text,length);
    t.wordsValues(text,length);
    puts("\n");
    puts("Numbers\n");
    Number n;
    n.stringtonumber(number);
    puts("\n");
    puts("Video size\n");
    videoMemory v;
    v.videoSize(800,600,24,5,60);
    return 0;
}
