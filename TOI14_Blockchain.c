/*
TASK: blockchain.c
LANG: C
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <stdio.h>
int main()//BLOCKCHAIN//
{
    int a,b,x,y,i,j,k,l,t,q;
    scanf("%d %d",&t,&q);
    int T[t][100][2],Q[q][100][2],n[t],m[q];
    for(i=0;i<t;i++)//ถูกตรวจสอบ//
    {
        scanf("%d",&n[i]);
        for(j=0;j<n[i]-1;j++)
        {
            scanf("%d %d",&T[i][j][0],&T[i][j][1]);
        }
    }
    for(i=0;i<q;i++)//ตัวตรวจสอบ//
    {
        scanf("%d",&m[i]);
        for(j=0;j<m[i]-1;j++) scanf("%d %d",&Q[i][j][0],&Q[i][j][1]);
        {
            
        }

    }
    for(x=0;x<q;x++)//ตัวตรวจสอบ ตรวจ ตัวถูกตรวจสอบ//
    {
        l=0;
        for(i=0;i<t;i++)
        {
            if(m[x]==n[i])
            {
                k=0;
                for(y=0;y<m[x]-1;y++)
                {
                    for(j=0;j<n[i]-1;j++)
                    {
                        if((Q[x][y][0]==T[i][j][0] && Q[x][y][1]==T[i][j][1]) || (Q[x][y][1]==T[i][j][0] && Q[x][y][0]==T[i][j][1]))
                        {
                            k++;
                            break;
                        }
                    }
                }
                if(k==m[x]-1)
                {
                    l++;
                }
            }
        }
        printf("\n%d",l);
    }
}