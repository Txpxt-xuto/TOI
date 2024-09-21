/*
TASK: technology.cpp
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include<bits/stdc++.h>
using namespace std;
const int INF = 30'000'000;
struct Point{
    int x,y;
    Point():x(0),y(0){}
    Point(int _x,int _y):x(_x),y(_y){}
    bool operator==(Point o){
        return x==o.x&&y==o.y;
    }
};
struct Cmp{
    bool operator()(const Point &l,const Point &r)const{
        return l.y<r.y||(l.y==r.y&&l.x<r.x);
    }
};
double dist(Point a,Point b){
    long long dx=a.x-b.x;
    long long dy=a.y-b.y;
    return sqrt(dx*dx+dy*dy);
}
void runcase(){
    int n,r,d,i;
    cin >> n >> r >> d;
    vector<Point> a(n);
    for(auto &[x,y]:a) cin >> x >> y;
    sort(a.begin(),a.end(),[&](Point l,Point r){
        return l.x<r.x||(l.x==r.x&&l.y<r.y);
    });
    for(i=1;i<n;i++)
    {
        if(a[i]==a[i-1])
        {
            cout << "N\n";
            return;
        }
    }
    double ans=INF;
    multiset<Point,Cmp> s;
    for(i=0,j=0;i<n;i++)
    {
        while(a[i].x-a[j].x>ans)
        {
            s.erase(s.find(a[j]));
            j++;
        }
        for(auto it=s.lower_bound(Point(-INF,a[i].y-floor(ans)));it!=s.end()&&it->y-a[i].y<=ans;it++) ans = min(ans,dist(a[i],*it));
        s.insert(a[i]);
    }
    cout << (ans>=d+r*2?'Y':'N') << '\n';
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int t(1);
    cin >> t;
    while(t--)runcase();
}