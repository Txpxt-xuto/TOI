/*
TASK: DICE
LANG: C
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <stdio.h>
#include <string.h>
int main()
{
    int i,j,k,n,m,x,y,z;
    scanf("%d",&n);
    char word[n][1000];
    for(i=0;i<n;i++)
    {
        scanf("%s",&word[i]);
    }
    for(i=0;i<n;i++)
    {
        int ON=1,FRONT=2,LEFT=3,BLACK=5,RIGHT=4,LOW=6;
        m = strlen(word[i]);
        for(j=0;j<m;j++)
        {
            if(word[i][j]=='B')
            {
                x=BLACK;
                y=LOW;
                z=ON;
                ON=FRONT;
                BLACK=z;
                LOW=x;
                FRONT=y;
            }
            else if(word[i][j]=='F')
            {
                x=BLACK;
                y=LOW;
                z=ON;
                ON=x;
                BLACK=y;
                LOW=FRONT;
                FRONT=z;
            }
            else if(word[i][j]=='L')
            {
                x=RIGHT;
                y=LOW;
                z=ON;
                ON=LEFT;
                RIGHT=z;
                LOW=x;
                LEFT=y;
            }
            else if(word[i][j]=='R')
            {
                x=RIGHT;
                y=LOW;
                z=ON;
                ON=x;
                RIGHT=y;
                LOW=LEFT;
                LEFT=z;
            }
            else if(word[i][j]=='D')
            {
                x=RIGHT;
                y=BLACK;
                z=FRONT;
                FRONT=LEFT;
                RIGHT=z;
                BLACK=x;
                LEFT=y;
            }
            else if(word[i][j]=='C')
            {
                x=RIGHT;
                y=BLACK;
                z=FRONT;
                FRONT=x;
                RIGHT=y;
                BLACK=LEFT;
                LEFT=z;
            }
        }
        printf("%d ",FRONT);
    }
}