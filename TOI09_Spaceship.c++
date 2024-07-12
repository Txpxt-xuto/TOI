/*
TASK: spaceship.cpp
LANG: C++
COMPILER: VS code
AUTHOR: Tapat Toungkul
ID: none
*/
#include<bits/stdc++.h>
using namespace std;
struct dataa
{
    long long x,y,z;
    int a,b,c;
    int id;
    bool operator < (const dataa&o) const
    {
        return id<o.id;
    }
};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    long long x,y,z;
    cin>>x>>y>>z;
    long long ans=LLONG_MAX;
    int m;
    cin>>m;
    dataa d[m];
    for(int i=0;i<m;i++)
    {
        cin>>d[i].x>>d[i].y>>d[i].z>>d[i].a>>d[i].b>>d[i].c;
        d[i].id=i;
    }
    do
    {
        long long temp=0;
        long long xx=x,yy=y,zz=z;
        int index=0;
        int a=n,b=n,c=n;
        while(!(a<=0&&b<=0&&c<=0))
        {
            long long xxx=d[index].x,yyy=d[index].y,zzz=d[index].z;
            temp+=(xx-xxx)*(xx-xxx)+(yy-yyy)*(yy-yyy)+(zz-zzz)*(zz-zzz);
            xx=xxx; 
            yy=yyy; 
            zz=zzz;
            a=max(0,a-d[index].a); 
            b=max(0,b-d[index].b); 
            c=max(0,c-d[index].c);
            index++;
        }
        ans=min(ans,temp);
    }while(next_permutation(d,d+m));
    cout<<ans;
}#include<bits/stdc++.h>
using namespace std;
struct dataa
{
    long long x,y,z;
    int a,b,c;
    int id;
    bool operator < (const dataa&o) const
    {
        return id<o.id;
    }
};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    long long x,y,z;
    cin>>x>>y>>z;
    long long ans=LLONG_MAX;
    int m;
    cin>>m;
    dataa d[m];
    for(int i=0;i<m;i++)
    {
        cin>>d[i].x>>d[i].y>>d[i].z>>d[i].a>>d[i].b>>d[i].c;
        d[i].id=i;
    }
    do
    {
        long long temp=0;
        long long xx=x,yy=y,zz=z;
        int index=0;
        int a=n,b=n,c=n;
        while(!(a<=0&&b<=0&&c<=0))
        {
            long long xxx=d[index].x,yyy=d[index].y,zzz=d[index].z;
            temp+=(xx-xxx)*(xx-xxx)+(yy-yyy)*(yy-yyy)+(zz-zzz)*(zz-zzz);
            xx=xxx; 
            yy=yyy; 
            zz=zzz;
            a=max(0,a-d[index].a); 
            b=max(0,b-d[index].b); 
            c=max(0,c-d[index].c);
            index++;
        }
        ans=min(ans,temp);
    }while(next_permutation(d,d+m));
    cout<<ans;
}