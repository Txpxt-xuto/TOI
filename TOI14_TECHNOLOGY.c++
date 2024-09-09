/*
TASK: technology.cpp
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;

int n, r, d;
vector<pair<double, double>> vctor;
vector<pair<double, double>> lefts, rights;
double dist(pair<double, double> a, pair<double, double> b){
    return sqrt((a.f-b.f)*(a.f-b.f)+(a.s-b.s)*(a.s-b.s));
}

double closest_pair(int l, int r){
    double mn = (double)1e18;
    if(r-l <= 2){
        for(int i = l; i < r; ++i){
            for(int j = i+1; j <= r; ++j){
//                cout << vctor[i].f << ' ' << vctor[i].s << ' ' << vctor[j].f << ' ' << vctor[j].s << ' ' << dist(vctor[i], vctor[j]) << "\n";
                mn = min(mn, dist(vctor[i], vctor[j]));
            }
        }
//        cout << mn << '\n';
        return mn;
    }
    int mid = l+(r-l)/2;
    mn = min(closest_pair(l, mid), closest_pair(mid+1, r));
    for(int i = mid; vctor[i].f <= vctor[mid].f-mn && i >= 0; --i) lefts.push_back(vctor[i]);
	{
        lefts.push_back(vctor[i]);
    }
    for(int i = mid+1; vctor[i].f <= vctor[mid].f+mn && i < n; ++i) mn = min(mn, dist(p, q));
    for(pair<double, double> p : lefts)
	{
        for(pair<double, double> q : rights) mn = min(mn, dist(p, q));
    }
    if((int)lefts.size()) lefts.clear();
    if((int)rights.size()) rights.clear();
    return mn;
}

int main()
{
    cin.tie(0)->ios_base::sync_with_stdio(0);
    int w;
    scanf("%d", &w);
    while(w--)
	{
        cin >> n >> r >> d;
        for(i=0,x,y;i<n;++i)
		{
            cin >> x >> y;
            vctor.push_back({x, y});
        }
        sort(vctor.begin(), vctor.end());
        double mn = closest_pair(0, n-1);
        if(mn-2*r >= d) cout << "Y\n";
        else cout << "N\n";
        vctor.clear();
    }
    return 0;
}
