/*
TASK: technology.cpp
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <stdio.h>
int main() //โจทย์ที่ 3 เชียงใหม่ไน่ทรัพย์//
{
    int n,m,i,j,point;
    scanf("%d %d",&n,&m);
    int num[n],cus[m*2];
    for(i=0;i<n;i++)
    {
        scanf("%d",&num[i]);
    }
    for(j=0;j<(m*2);j++) scanf("%d",&cus[j]);
    {
        scanf("%d",&cus[j]);
    }
    for(j=0;j<(m*2);j=j+2)
    {
        point=0;
        for(i=cus[j];i<n;i++)
        {
            if(num[i]>=0) point=point+num[i];
            else
            {
                if(cus[j+1]>=(num[i]*(-1)))
                {
                    cus[j+1]=cus[j+1]+num[i];
                    if(cus[j+1]==0) break;
                }
                else break;
            }
        }
        printf("%d\n",point);
    }
}
