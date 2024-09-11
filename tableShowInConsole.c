#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*
    int i;
    for(i=0; i<256; i++)
    {
        printf("%c - %d \n", i,i);
    }

    int i;
    for(i=10;i>=0;i--)
    {
        printf("%d\n",i);
    }
    */
    int i;
    for(i=0;i<=5;i++)
    {
        if(i==0||i==5)
        {
            printf("+---------+\n");
        }
        else
        {
            if(i==3)
            {
                printf("+----+----+\n");
            }
            printf("|    |    |\n");
        }

    }
    return 0;
}
