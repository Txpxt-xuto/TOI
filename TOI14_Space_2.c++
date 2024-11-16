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
        {
            if(seg[i<<1].b<seg[(i<<1)+1].b) seg[i]=seg[i<<1];
            else seg[i]=seg[(i<<1)+1];
            continue;
        }
        if(seg[i<<1].a<seg[(i<<1)+1].a) seg[i]=seg[i<<1];
        else if(seg[i<<1].a>seg[(i<<1)+1].a) seg[i]=seg[(i<<1)+1];
    }
}
pair query(int l,int r){
    pair y={inf,0};
    l+=(1<<(S-1)),r+=(1<<(S-1))+1;
    for(;l<r;l>>=1,r>>=1)
    {
        if(l&1)
        {
            if(y.a>seg[l].a)
            {
                y.a=seg[l].a;
                y.b=seg[l++].b;
            }
        }
        if(r&1)
        {
            if(y.a>seg[r-1].a)
            {
                y.a=seg[r-1].a;
                y.b=seg[--r].b;
            }
        }
    }
    return y;
}

typedef struct {
    pair* head;
    int size;
    int capa;
}imvec;
void update(imvec* v)
{
    if(v->capa==v->size)
    {
        v->capa*=2;
        v->head=(pair*)realloc(v->head,v->capa*sizeof(pair));
    }
}
void pb(imvec* v,int x,int y){
    v->head[v->size].a=x;
    v->head[v->size].b=y;
    v->size++;
    update(v);
}
void pop(imvec* v)
{
    v->size--;
}
void innit(imvec* v)
{
    v->capa=2;
    v->size=0;
    v->head=(pair*)calloc(2,sizeof(pair));
}
int main()
{
    for(int i=0;i<(1<<S);i++) seg[i].a=inf;
    int n,m,k,start,ii=0;
    scanf("%d %d %d %d",&n,&m,&k,&start);
    imvec v[n+1];
    imvec path;
    int dis[n+1],gec[k],par[n+1];
    bool vis[n+1];
}