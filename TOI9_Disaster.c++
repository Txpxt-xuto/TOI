#include <bits/stdc++.h>
using namespace std;
int n,i;
int al[30];
vector<pair<int,int>> graph[30];
bool ans=false;
char rans[309];
bool visited[309];
void dfs(int st,int cnt)
{
    rans[cnt]=char(st+'A');
    if(cnt==n)
	{
        for(int i=0;i<=n;i++) cout << rans[i] << " ";

        exit(0);
    }
    for(auto x:graph[st])
	{
        if(!visited[x.first])
		{
            visited[x.first]=true;
            dfs(x.second,cnt+1);
            visited[x.first]=false;
        }
    }
    return;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin >> n;
    for(int i=0;i<n;i++){
        string s;cin >> s;
        al[s[0]-'A']++;
        al[s[1]-'A']++;
        graph[s[0]-'A'].push_back({i,s[1]-'A'});
        graph[s[1]-'A'].push_back({i,s[0]-'A'});
    }
    for(i=0;i<26;i++)
	{
        if(al[i]%2==1)
		{
            ans=true;
            dfs(i,0);
            return 0;
        }
    }
    if(!ans) dfs(0,0);
    return 0;
}
