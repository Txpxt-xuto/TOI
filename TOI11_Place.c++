#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    int l,x,y;
} pii;
pii a[200050];
int pa[200050];

int find(int v){
    if(pa[v]==v) return v;
    return pa[v]=find(pa[v]);
}

void U(int a,int b){
    a=find(a);
    b=find(b);
    if(a!=b) pa[a]=b;
}

int com(const void *a,const void *b){
    const pii *num1=(pii*)a;
    const pii *num2=(pii*)b;
    if(num1->l > num2->l){
        return -1;
    }
    else return +1;
}

int main(){
    int n,m;
    scanf("%d%d",&m,&n);
    for(int i=1;i<=200000;i++) pa[i]=i;
    for(int i=1;i<=n;i++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        a[i].l=w-1;
        a[i].x=u;
        a[i].y=v;
    }
    qsort(a+1,n,sizeof(pii),com);
   // for(int i=1;i<=n;i++){
     //   printf("%d %d %d\n",a[i].l,a[i].x,a[i].y);
   // }
    long long int ans=0;

    for(int i=1;i<=n;i++){
        int ll=a[i].l;
        int xx=a[i].x;
        int yy=a[i].y;
        if(find(xx)==find(yy)) continue;
        ans+=ll;
        U(xx,yy);
    }

    printf("%lld",ans);
}