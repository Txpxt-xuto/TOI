/*
TASK: barrier.cpp
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <bits/stdc++.h>
using namespace std;
int i;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,maxlen;
    cin >> n >> maxlen;
    vector <int> home(n,0);
    int temp;
    cin >> temp;
    home[0]+=temp;
    for(i=1;i<n;i++)
    {
        cin >> temp;
        home[i]+=home[i-1]+temp;
    }
    int maxsum=0,minlen=maxlen;
    deque <int> index;
    for(i=0;i<n;i++)
    {
        while(!index.empty() and i-index.front()>maxlen)
        {
            index.pop_front();
        }
        while(!index.empty() and home[index.back()]>=home[i])
        {
            index.pop_back();
        }
        index.push_back(i);
        if(home[index.back()]-home[index.front()]>maxsum)
        {
            maxsum=home[index.back()]-home[index.front()];
            minlen=i-index.front();
        }
        else if(minlen==i-index.front())
        {
            minlen=min(minlen,i-index.front());
        }
    }
    if(!maxsum) cout << "0\n0";
    else cout << maxsum << '\n' << minlen;
}