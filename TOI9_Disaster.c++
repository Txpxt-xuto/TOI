#include<iostream>
#include<vector>
using namespace std;
int n,j;
bool visit[305]={}, tf=false;
char ans[305];
vector<vector<pair<char, int> > > v(26);
void walk(int i, int cnt) 
{
	ans[cnt]=(char)(i+'A');
	if(cnt==n) 
    {
		for(j=0;j<=n;j++) cout << ans[j] << " ";
		tf=true;
		return ;
	}
	if(!tf) 
    {
		for(j=0;j<v[i].size();j++) 
        {
			if(!visit[v[i][j].second]) 
            {
				visit[v[i][j].second]=1;
				walk(v[i][j].first-'A', cnt+1);
				visit[v[i][j].second]=0;
			}
		}
	}
}
int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); 
    cout.tie(NULL);
	cin >> n;
	int i;
	char a, b;
	for(i=0;i<n;i++) 
    {
		cin >> a >> b;
		v[a-'A'].push_back({b, i});
		v[b-'A'].push_back({a, i});
	}
	for(i=0;i<26;i++) 
    {
		if (v[i].size()%2==1) 
        {
			walk(i,0);
			break;
		}
	}
	if (!tf) walk(0,0);
	return 0;
}