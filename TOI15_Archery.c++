#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    scanf("%d",&n);
    vector <int> layer(n);
    vector <int> hole(n);
    int mnlayer=INT_MAX;
    for(int i=0;i<n;i++){
        scanf("%d",&layer[i]);
        mnlayer=min(mnlayer,layer[i]);
    }
    for(int i=0;i<n;i++){
        scanf("%d",&hole[i]);
    }
    int count,ans=INT_MAX,real;
    for(i=1;i<mnlayer;i++)
    {
        count=0;
        for(int j=0;j<n;j++)
        {
            if(hole[j]>i) count+=hole[j]-i;
            else if(hole[j]<i) count+=hole[j]+layer[j]-i+1;
        }
        if(count<ans)
        {
            ans=count;
            real=i;
        }
    }
    printf("%d %d",real,ans);
}