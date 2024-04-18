#include <bits/stdc++.h>

using namespace std;
vector<vector<int> > a,v;
vector<int> ans;
void solve(int p,int x,int y,int d)
{
    //cout << x << ' ' << y << ' ' << d << '\n';
    int tmp=a[x][y];
    if(tmp==-1){
        ans.push_back(p);
        return;
    }
    if(tmp==11){
        v[x][y]=1;
        if(d==1)solve(p+1,x,y-1,2);
        else solve(p+1,x-1,y,3);
    }
    if(tmp==12){
        v[x][y]=1;
        if(d==1)solve(p+1,x,y+1,4);
        else solve(p+1,x-1,y,3);
    }
    if(tmp==13){
        v[x][y]=1;
        if(d==3)solve(p+1,x,y-1,2);
        else solve(p+1,x+1,y,1);
    }
    if(tmp==14){
        v[x][y]=1;
        if(d==3)solve(p+1,x,y+1,4);
        else solve(p+1,x+1,y,1);
    }
    if(tmp==21){
        v[x][y]=1;
        if(d==1)solve(p+1,x+1,y,1);
        else solve(p+1,x-1,y,3);
    }
    if(tmp==22){
        v[x][y]=1;
        if(d==2)solve(p+1,x,y-1,2);
        else solve(p+1,x,y+1,4);
    }
    if(tmp==31){
        if(d==1){
            a[x][y]=22;
            solve(p+1,x+1,y,1);
        } else if(d==3){
            a[x][y]=22;
            solve(p+1,x-1,y,3);
        } else if(d==2){
            a[x][y]=21;
            solve(p+1,x,y-1,2);
        } else {
            a[x][y]=21;
            solve(p+1,x,y+1,4);
        }
    }

}
int main()
{
    int r,c;
    cin >> r >> c;
    a=vector<vector<int> > (r+2,vector<int> (c+2,-1));
    v=vector<vector<int> > (r+2,vector<int> (c+2,0));
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++) cin >> a[i][j];
    }
    for(int i=1;i<=c;i++) if((a[1][i]==11||a[1][i]==12||a[1][i]==21||a[1][i]==31)&&!v[1][i]) solve(0,1,i,1);
    for(int i=1;i<=c;i++) if((a[r][i]==13||a[r][i]==14||a[r][i]==21||a[r][i]==31)&&!v[r][i]) solve(0,r,i,3);
    for(int i=1;i<=r;i++) if((a[i][1]==11||a[i][1]==13||a[i][1]==22||a[i][1]==31)&&!v[i][1]) solve(0,i,1,4);
    for(int i=1;i<=r;i++) if((a[i][c]==12||a[i][c]==14||a[i][c]==22||a[i][c]==31)&&!v[i][c]) solve(0,i,c,2);
    cout << ans.size() << '\n';
    for(int i=0;i<ans.size();i++) cout << ans[i] << ' ';
    return 0;
}