/*
TASK: food
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include<bits/stdc++.h>
using namespace std;
string order;
map<char,bool> mp;
int main()
{
    int n,m,i;
    cin>>n>>m;
    for(i=1;i<=n;i++) order.push_back(i+'0');
    for(i=0;i<m;i++)
    {
        char c;
        cin>>c;
        mp[c]=true;
    }
    do
    {
        if(!mp[order[0]])
        {
            for(auto c:order) cout<<c<<" ";
            cout<<"\n";
        } 
    } 
    while (next_permutation(order.begin(),order.end()));
}