/*
TASK: technology.cpp
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int MX = 1000002;
struct event {
    int x;
    int h;
    int o;
    bool operator < (const event&temp) const {
        return x < temp.x;
    }
};
struct fenwick {
    int c[MX];
    void add(int idx,int val) {
        while(idx < MX) c[idx] += val,idx += (idx&-idx);
    }
    int find(int idx) {
        int tmp = 0;
        while(idx > 0) tmp += c[idx],idx -= (idx&-idx);
        return tmp;
    }
}f1;
int binarySl(int T) {
    int st = 1; int en = MX;
    while(st < en) {
        int mid = (st + en) / 2;
        if(f1.find(mid) > T) st = mid + 1;
        else en = mid;
    }
    return en;
}
int binarySH(int T) {
    int st = 1; int en = MX;
    while(st < en) {
        int mid = (st + en + 1) / 2;
        if(f1.find(mid) < T) en = mid - 1;
        else st = mid;
    }
    return en;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll N,T;
    int i;
    cin >> N >> T;
    vector<event> eventX;
    vector<int> posX;
    for(i=0;i<N;i++)
    {
        int s,h,w,o;
        cin >> s >> h >> w >> o;
        eventX.push_back({s,h,o});
        eventX.push_back({s + w,h,-o});
        posX.push_back(s);
        posX.push_back(s + w);
    }
    sort(eventX.begin(),eventX.end());
    sort(posX.begin(),posX.end());
    posX.resize(unique(posX.begin(),posX.end()) - posX.begin());
    int ans = 0;
    int eventptr = 0;
    int lastPos = 0;
    for(i : posX)
    {
        int rlow = binarySl(T);
        int rhigh = binarySH(T);
        if(f1.find(rlow) == T && f1.find(rhigh) == T) ans += (rhigh - rlow + 1) * (i - lastPos);
        lastPos = i;
        if(eventptr < eventX.size())
        {
            int x = eventX[eventptr].x;
            int h = eventX[eventptr].h;
            int o = eventX[eventptr].o;
            while(x == i)
            {
                f1.add(1,o);
                f1.add(h + 1,-o);
                eventptr++;
                x = eventX[eventptr].x;
                h = eventX[eventptr].h;
                o = eventX[eventptr].o;
            }
        }
    }
    cout << ans;
    return 0;
}