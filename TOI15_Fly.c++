#include<bits/stdc++.h>
#define st first
#define nd second
using namespace std;
int i,j;
int ea[2005][2];
pair<int,int>  inv[2][150],avi[20][20][50],temp[150];
int a[30][30],sz[2],mi=1e9;
char s[2];
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int row,col,val,x,y;
    cin >> row >> col;
    int bi,le,itr,itr2,mod=2*col,n;
    for(i=1;i<=row;i++)
    {
        for(j=0;j<2;j++)
        {
            cin >> val >> s;
            if(s[0]=='R') ea[i][j]=val;
            else ea[i][j]=2*col-val;
        }
    }
    for(i=1;i<col;i++)
    {
        inv[0][0]= {0,2*col};
        sz[0]=1;
        bi=1;
        for(j=1;j<=row;j++)
        {
            le = inv[1-bi][0].st+1;
            for(k=0;k<2;k++)
            {
                val=(ea[j][k]+le)%mod;
                x=(i-val)%mod;
                if(x<0) x+=mod;
                y=(mod-val-i)%mod;
                if(y<0) y+=mod;
                itr=0,itr2=0;
                if(x<y) 
                {
                    if(x>0) avi[k][0][itr++]= {le,le+x-1};
                    avi[k][1][0]= {le+x+1,le+y-1};
                    if(y!=2*col-1) avi[k][0][itr++]= {le+y+1,le+2*col-1};
                    a[k][0]=itr;
                    a[k][1]=1;
                }
                else
                {
                    if(y>0) {
                        avi[k][1][itr++]= {le,le+y-1};
                    }
                    avi[k][0][0]= {le+y+1,le+x-1};
                    if(x!=2*col-1||y!=0) avi[k][1][itr++]= {le+x+1,le+2*col-1};
                    a[k][0]=1;
                    a[k][1]=itr;
                }
            }
            itr=0;
            for(int k=0; k<2; k++)
            {
                for(int l=0; l<a[0][k]; l++)
                {
                    for(int m=0; m<a[1][1-k]; m++)
                    {
                        x=max(avi[0][k][l].st,avi[1][1-k][m].st);
                        y=min(avi[0][k][l].nd,avi[1][1-k][m].nd);
                        if(x<=y) {
                            temp[itr++]= {x,y};
                        }
                    }
                }
            }
            sort(temp,temp+itr);
            n=unique(temp,temp+itr)-temp;
            itr=0,itr2=0;
            for(int k=0; k<n; k++)
            {
                while(itr<sz[1-bi]&&inv[1-bi][itr].nd<temp[k].st-1) {
                    itr++;
                }
                if(itr>=sz[1-bi]) {
                    break;
                }
                if(inv[1-bi][itr].st>=temp[k].nd) {
                    continue;
                }
                inv[bi][itr2++]= {max(inv[1-bi][itr].st+1,temp[k].st),temp[k].nd};
            }
            if(itr2<=0) {
                break;
            }
            sz[bi]=itr2;
            bi=1-bi;
        }
        if(itr2>0)
        {
            mi=min(inv[1-bi][0].st+1,mi);
        }
    }
    cout << mi;
}