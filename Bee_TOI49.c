/*
TASK: BEE
LANG: C
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <stdio.h>
int main()
{
    // input : i j -1
    int i,j,k,x;
    int fibo1=0,fibo2=1,fibo=fibo1+fibo2;
    int bee1=4,bee=bee1;
    scanf("%d %d %d",&i,&j,&k);
    for (x=1;x<i+1;x++) 
    {
        fibo1 = fibo2;
        fibo2 = fibo;
        fibo = fibo1 + fibo2;
        if(fibo>=3)
        {
            bee=bee1+fibo;
            bee1=bee;
        }
    }
    printf("%d %d\n",bee-fibo,bee);//คำตอบของปี i โดยเป็น จำนวนมดงาน จำนวนมดทั้งหมด
    fibo1=0;
    fibo2=1;
    fibo=fibo1+fibo2;
    bee1=4;
    bee=bee1;
    for (x=1;x<j+1;x++) 
    {
        fibo1 = fibo2;
        fibo2 = fibo;
        fibo = fibo1 + fibo2;
        if(fibo>=3)
        {
            bee=bee1+fibo;
            bee1=bee;
        }
    }
    printf("%d %d",bee-fibo,bee);//คำตอบของป j โดยเป็น จำนวนมดงาน จำนวนมดทั้งหมด
}