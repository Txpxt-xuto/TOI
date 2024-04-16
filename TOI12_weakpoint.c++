
#include <bits/stdc++.h>
#define f first
#define s second
#define MAXN 500005
using namespace std;
vector<int> graph[MAXN];
int visited[MAXN],cycroot,maxch=0,maxv=1000000,found=0;

pair<int,int> dfs(int i,int prev)
{
    int sum=0,ignore=0,cycsum=0;
    visited[i]=1;
    for(auto v: graph[i]){
        if(v==prev) continue;
        if(visited[v]){
            if(!found){
                cycroot=v;
                ignore=1;
                found=1;
            }
            continue;
        }
        pair<int,int> ch=dfs(v,i);
        sum+=ch.f;
        if(ch.s){
            ignore=1;
            cycsum=ch.f;
        }
    }
    if(prev && (maxch<sum-cycsum || (maxch==sum-cycsum && maxv>i))){
        maxch=sum-cycsum;
        maxv=i;
    }
    if(ignore && prev==cycroot) ignore=0;
    pair<int,int> res(sum+1,ignore);
    return res;
}
int main()
{
    int N,M,a,b;
    scanf("%d %d",&N,&M);
    for(int i=0; i<N; i++){
        scanf("%d %d",&a,&b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(M,0);
    cout << maxv << endl << maxch;
    return 0;
}