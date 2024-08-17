/*
TASK: truck.cpp
LANG: C++
AUTHOR: Tapat Toungsakul
Center: Home
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pint;
int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll i, j;
    ll e, v, a, b, w, sum = 0, cnt = 0;
    cin >> e >> v;
    ll deg[v + 1] = {};
    vector<pint> adj[v + 1];
    for(i=0;i<e;i++)
    {
        cin >> a >> b >> w;
        deg[a]++;
        deg[b]++;
        sum += w;
        adj[a].push_back({w, b});
        adj[b].push_back({w, a});
    }
    for(i=0;i<=v;i++) cnt += deg[i]%2;
    if(cnt == 0) cout << sum;
    else
    {
        vector<ll> odd;
        do {
            vector<ll> temp;
            for(i=0;i<=v;i++)
            {
                if(deg[i] == 1)
                {
                    deg[i] = 0;
                    for(pint p : adj[i])
                    {
                        if(deg[p.second] > 0)
                        {
                            deg[p.second]--;
                            sum += p.first;
                        }
                    }
                }
            }
            cnt = 0;
            for(i=0;i<=v;i++) cnt += (deg[i] == 1);
        } while (cnt > 0);
        cnt = 0;
        for(i=0;i<=v;i++){
            if(deg[i]%2 == 1) 
            {
                odd.push_back(i);
                cnt++;
            }
        }
        if(cnt == 0) cout << sum;
        else 
        {
            ll dis[cnt][v + 1], pro[v + 1] = {};
            for(i=0;i<cnt;i++) 
            {
                for(j=0;j<=v;j++) dis[i][j] = INT_MAX;
            }
            priority_queue<pint, vector<pint>, greater<pint>> pq;
            dis[0][odd[0]] = 0;
            pq.push({dis[0][odd[0]], odd[0]});
            while (!pq.empty()) 
            {
                a = pq.top().second;
                pq.pop();
                if (!pro[a]) 
                {
                    pro[a] = 1;
                    for (pint p : adj[a]) {
                        w = p.first;
                        b = p.second;
                        if (!pro[b]) 
                        {
                            dis[0][b] = min(dis[0][b], dis[0][a] + w);
                            pq.push({dis[0][b], b});
                        }
                    }
                }
            }
            if (cnt == 2) 
            {
                sum += dis[0][odd[1]];
                cout << sum;
            }
            else 
            {
                for(i=1;i<=2;i++) 
                {
                    ll pro2[v + 1] = {};
                    priority_queue<pint, vector<pint>, greater<pint>> pq2;
                    dis[i][odd[i]] = 0;
                    pq2.push({dis[i][odd[i]], odd[i]});
                    while (!pq2.empty()) {
                        a = pq2.top().second;
                        pq2.pop();
                        if (!pro2[a]) {
                            pro2[a] = 1;
                            for (pint p : adj[a]) {
                                w = p.first;
                                b = p.second;
                                if (!pro2[b]) {
                                    dis[i][b] = min(dis[i][b], dis[i][a] + w);
                                    pq2.push({dis[i][b], b});
                                }
                            }
                        }
                    }
                }
                sum += min(min(dis[0][odd[1]] + dis[2][odd[3]], dis[0][odd[2]] + dis[1][odd[3]]), dis[0][odd[3]] + dis[1][odd[2]]);
                cout << sum;
            }
        }
    }
    return 0;
}