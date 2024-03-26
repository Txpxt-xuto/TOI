/*
TASK: jail
LANG: C
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <stdio.h> //คำตอบเหมือนกันแต่ช้า
int main()
{
    int i,j,k,n,m,num;
    scanf("%d %d",&n,&m);
    int Jail[n],a[num],loop=0;
    for(i=0;i<n;i++) Jail[i]=i+1;
    num=n;
    while(num!=0)
    {
        printf("%d ",Jail[(loop+m-1)%num]);
        Jail[(loop+m-1)%num]=0;
        loop=(loop+m-1)%num;
        num=0;
        for(i=0;i<n;i++) if(Jail[i]!=0) num++;
        for(j=0;j<num;j++)
        {
            for(k=0;k<num+1;k++)
            {
                if(Jail[k]!=0)
                {
                    a[j]=Jail[k];
                    Jail[k]=0;
                    break;
                }
            }
        }
        for(i=0;i<num;i++) Jail[i]=a[i];
    }
}