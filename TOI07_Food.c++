/*
TASK: food
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include<bits/stdc++.h>
using namespace std;
string order;
map<char,bool> probability;
int main()
{
    int n,m,i;
    cin >> n >> m;
    for(i=1;i<=n;i++) order.push_back(i+'0');
    for(i=0;i<m;i++)
    {
        char c;
        cin>>c;
        probability[c]=true;
    }
    do
    {
        if(!probability[order[0]])
        {
            for(auto c:order) cout<<c<<" ";
            cout<<"\n";
        } 
    } 
    while (next_permutation(order.begin(),order.end()));
}