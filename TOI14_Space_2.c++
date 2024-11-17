/*
TASK: space.cpp
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define S 10
#define inf 2e9
int max(int a,int b){
    return a>b ? a:b;
}
int min(int a,int b){
    return a<b ? a:b;
}
typedef struct{
    int a;
    int b;
}pair;
pair seg[(1<<S)];
void updateseg(int idx,int val,int f){
    idx+=(1<<(S-1));
    seg[idx].a=val;
    seg[idx].b=f;
    for(idx>>=1;idx>0;idx>>=1)
    {
        if(seg[idx<<1].a==seg[(idx<<1)+1].a)
        {
            if(seg[idx<<1].b<seg[(idx<<1)+1].b) seg[idx]=seg[idx<<1];
            else seg[idx]=seg[(idx<<1)+1];
            continue;
        }
        if(seg[idx<<1].a<seg[(idx<<1)+1].a) seg[idx]=seg[idx<<1];
        else if(seg[idx<<1].a>seg[(idx<<1)+1].a) seg[idx]=seg[(idx<<1)+1];
    }
}
void popseg()
{
    int i=1;
    while((i<<1)<(1<<S))
    {
        if(seg[i<<1].a==seg[i].a&&seg[i<<1].b==seg[i].b) i<<=1;
        else i=(i<<1)+1;
    }
    seg[i].a=inf;
    seg[i].b=0;
    for(i>>=1;i>0;i>>=1)
    {
        if(seg[i<<1].a==seg[(i<<1)+1].a)
        if(seg[i<<1].a<seg[(i<<1)+1].a) seg[i]=seg[i<<1].a) seg[i]=seg[(i<<1)+1];
    }
}