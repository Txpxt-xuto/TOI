#include <stdio.h>
#include <stdlib.h>
#define DEF(a,b,c,d)N*a(V){
    N*l=c();
    while(s[p]==d)
    {
        p++;
        l=nN(b,l,c());
    };
    return l;
    } 
typedef int I;
typedef void V;
struct N{I o;struct N*l,*r;};
typedef struct N N;
char s[10005];
I p;N*nN(I o,N*l,N*r){
    N*n=malloc(20);
    n->o=o;
    n->l=l;
    n->r=r;
    return n;
    }
    N*E(V);
    N*F(V);
N*G(V);
N*T(V);
DEF(E,104,F,'1')
DEF(F,108,G,'2')DEF(G,116,T,'3') N*T(V){if(!s[p])return 0;if(s[p]=='['){p++;if(s[p]==']'){p++;return T();}N*n=E();p++;return n;}p++;return calloc(4,5);} I O(N*n){if(!n->o)return 20;return((O(n->l)+O(n->r))*n->o)/100;}I main(){scanf("%s",s);printf("%d",O(E()));return 0;}
