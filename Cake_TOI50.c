/*
TASK: CAKE
LANG: C
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <stdio.h>
int main()
{
    int i,j,n,cake,A=0,B=0,C=0,D=0,E=0;
    scanf("%d",&n);
    if(n<=10 && n>=1)
    {int a[n],b[n],c[n],d[n],e[n];
        for(i=0;i<n;i++)
        {
            scanf("%d %d %d %d %d",&a[i],&b[i],&c[i],&d[i],&e[i]);
        }
        for(i=0;i<n;i++)
        {
            A+=a[i];
            B+=b[i];
            C+=c[i];
            D+=d[i];
            E+=e[i];
        }
        A*=1000;
        B*=750;
        C*=500;
        D*=250;
        E*=125;
        cake=A+B+C+D+E;
        if((cake%1000)!=0)
        {
            printf("%d",(cake/1000)+1);
        }
        else
        {
            printf("%d",(cake/1000));
        }
    }
}