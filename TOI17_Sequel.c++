/*
TASK: Sequel
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <bits/stdc++.h>
using namespace std;
int mod=250;
int main()
{
    int n,q,a,b,k;
    cin>>n>>q;
    vector<int>v;
    vector<int>dp[n];
    for(int i=0;i<n;i++)
    {
        cin>>a;
        v.push_back(a);
    }
    for(int i=n-1;i>=0;i--)
    {
        dp[i].push_back(0);
        for(int j=1;j<=mod;j++)
        {
            if(i+j>=n)
            {
                dp[i].push_back(v[i]);
            }
            else
            {
                dp[i].push_back(v[i]+dp[i+j][j]);
            }
        }
    }
    for(int i=0;i<q;i++)
    {
        cin>>a>>k>>b;
        a--;
        b--;
        if(k>mod)
        {
            int l=a;
            int sum=0;
            while(l<=b)
            {
                sum=sum+v[l];
                l+=k;
            }
            cout<<sum<<" ";
        }
        else
        {
            int sum = dp[a][k],k1 = a+((b-a)/k+1)*k;
            int ;
            if(k1<n) sum = sum-dp[k1][k];
            cout << sum << " ";
        }
    }
    return 0;
}