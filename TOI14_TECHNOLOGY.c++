/*
TASK: technology.cpp
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <stdio.h>
int main()
{
    int n,m,i,j,point;
    scanf("%d %d",&n,&m);
    int num[n],cus[m*2];
    for(i=0;i<n;i++) scanf("%d",&num[i]);
    for(j=0;j<(m*2);j++) scanf("%d",&cus[j]);
    for(j=0;j<(m*2);j=j+2)
    {
        point=0;
        for(i=cus[j];i<n;i++)
        {
            if(num[i]>=0) point=point+num[i];
            else
            {