/*
TASK: food
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include<bits/stdc++.h>
using namespace std;
string s;
map<char,bool> mp;
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        s.push_back(i+'0');
    for(int i=0;i<m;i++)
    {
        char c;
        cin>>c;
        mp[c]=true;
    }
    do
    {
        if(!mp[s[0]])
        {
            for(auto c:s)
                cout<<c<<" ";
            cout<<"\n";
        } 
    } 
    while (next_permutation(s.begin(),s.end()));
    
    return 0;
}