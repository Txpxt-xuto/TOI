/*
TASK: cats.cpp
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll N,maxx = 0,minn = 1e9;
vector<int> vec;
int main()
{
    int i;
    scanf("%d",&N);
    for(i=0;i<N;i++)
    {
        int x;
        scanf("%d",&x);
        vec.push_back(x);
        if(x > maxx) maxx = x;
    }
    ll ans = maxx;
    ll L = 0,R = maxx;
    while(L <= R)
    {
        ll mid = (L+R)/2,check = 1;
        queue<int> q;
        for(i=0;i<N;i++)
        {
            if(vec[i] > mid)
            {
                if(q.empty() == 1) q.push(vec[i]);
                else
                {
                    if(q.front() == vec[i]) q.pop();
                    else
                    {
                        check = 0;
                        break;
                    }
                }
            }
        }
        if(check == 1)
        {
            ans = mid;
            R = mid - 1;
        }
        else L = mid + 1;
    }
    printf("%lld",ans);

}