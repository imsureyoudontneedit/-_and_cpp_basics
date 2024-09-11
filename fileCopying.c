#include <stdio.h>
#include <stdlib.h>

void copy(int picname, int copyname){
    FILE *orig=fopen(picname,"rb"), *copy=fopen(copyname,"wb");
        fseek(orig,0,SEEK_END);
        int size=ftell(orig);
        char *m = malloc(size);
        rewind(orig);
        fread(m,size,1,orig);
        fwrite(m,size,1,copy);
        free(m);
        fclose(orig);
        fclose(copy);
}

int main(){
    copy("original.png","copyoforiginal.png");
    return 0;
}
