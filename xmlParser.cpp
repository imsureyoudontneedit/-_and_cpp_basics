#include <iostream>
#include<stdio.h>
using namespace std;

class XMLParser{
    private:
        char *xml;
    public:
        XMLParser(char *xml){
            this->xml=xml;
        }
        char *getItem(char *ItemName){

        }
};
class FileIO{
private:
    FILE *f;
    int fileSize;
public:
    FileIO(char *fileName, char *mode){
        f=fopen(fileName,mode);
        fileSize=0;
    }

    ~FileIO(){
        fclose(f);
    }

    char readChar(){
        return fgetc(f);
    }

    char * readText(){
        char *file=new char[getSize()];
        int i;
        for(i=0;i<fileSize;i++)
            file[i]=fgetc(f);
        file[i]=0;
        rewind(f);
        return file;
    }

    char readCharFromPos(int pos){
        char *file=new char[getSize()];
        fseek(f,pos,SEEK_SET);
        char c=file[pos];
        rewind(f);
        return c;
    }

    char *readTextFromPos(int pos){
        char *file=new char[getSize()];
        int i;
        fseek(f,pos,SEEK_SET);
        for(i=0;i<fileSize;i++)
            file[i]=fgetc(f);
        file[i]=0;
        rewind(f);
        return file;
    }

    void writeChar(char ch){
        fputc(ch,f);
    }

    void writeText(char *string){
        fputs(string,f);
    }
    void writeCharToPos(int pos,char symb){
        fseek(f,pos,SEEK_SET);
        fputc(symb,f);
        rewind(f);
    }
    void writeStringToPos(int pos,char *string){
        fseek(f,pos,SEEK_SET);
        fputs(string,f);
        rewind(f);
    }
    int getSize(){
        fseek(f,0,SEEK_END);
        fileSize=ftell(f);
        rewind(f);
        return fileSize;
    }

};

int main()
{
    FileIO F("components.xml","r+");
    char *xmln=F.readText();
    XMLParser xml(xmln);
    return 0;
}
