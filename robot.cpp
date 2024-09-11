#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main()
{
    int position = 0;
    int i = 0;
    char pos[80];
    char alph[6]={'1','2','3','B','H','K'};
    cout << "Vvedite napravlenie kyda vi xotite Hanpavit' robota dlya etogo ispol'zyite angliskie 'B' dlay togo chto bi napravit' robota vverh i 'H' chto bi otpravit' robota vniz: ";
    scanf("%s",pos);
    printf("%s\n", pos);
        for(int j=0; j<80;j++){
            if(pos[j]=='B')
                position = position + 1;
            if(pos[j]=='H')
                position = position - 1;
            if(pos[j]=='2B')
                position = position + 2;
            if(pos[j]=='2H')
                position = position - 2;
            if(pos[j]=='3B')
                position = position + 3;
            if(pos[j]=='3H')
                position = position - 3;
            if(pos[j]=='K')
                break;
    }
    printf("%d\n",position);
    return 0;
}
