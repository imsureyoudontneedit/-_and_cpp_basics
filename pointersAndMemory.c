#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*
    int size = 20,i;
    int *m = calloc(size,sizeof(int));
    for(i = 0; i < size; i++)
        printf("%d ",m[i]);
    */
    /*
        int size = 20,i;
        int *m = calloc(size,sizeof(int));
        for(i = 0; i < size; i++){
            m[i] = 6;
            printf("%d ",m[i]);
    }
    int resize = size + (size*2);
    m = realloc(m, resize);
    for(i = size; i < resize; i++){
        m[i]=9;
        printf("%d ",m[i]);
    }
    */
    int **m = calloc(20,sizeof(int**)),i,j;
    for(i = 0;i < 20;i++)
        m[i] = calloc(65,sizeof(int**));
    for(i = 0; i < 20;i++){
        for(j = 0; j < 65;j++)
            printf("%d",m[i][j]);
        puts(" ");
    }

    return 0;
}
