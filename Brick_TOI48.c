/*
TASK: BRICK
LANG: C
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <stdio.h>
int main()
{
    int N,M,i,j,k,count;
    scanf("%d %d",&N,&M);
    char Brick[N][M];
    int a[M];
    for(i=0;i<N;i++)
    {
        scanf("%s",&Brick[i]);
    }
    for(j=0;j<M;j++)
    {
        scanf("%d",&a[j]);
    }
    for(j=0;j<M;j++)
    {
        count=0;
        for(i=0;i<N;i++)
        {
            if(Brick[i][j]=='O')
            {
                for(k=i-a[j];k<i;k++)
                {
                    Brick[k][j]='#';
                }
                break;
            }
            else if(Brick[i][j]!='O')
            {
                count+=1;
            }
        }
        if(count==N)
        {
            for(k=N-a[j];k<N;k++)
            {
                Brick[k][j]='#';
            }
        }
    }
    for(i=0;i<N;i++)
    {
        for(j=0;j<M;j++)
        {
            printf("%c",Brick[i][j]);
        }
        printf("\n");
    }
}