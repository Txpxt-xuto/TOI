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
    for(int i=1;i<mnlayer;i++){
        count=0;
        for(int j=0;j<n;j++){
            if(hole[j]>i){
                count+=hole[j]-i;
            }
            else if(hole[j]<i){
                count+=hole[j]+layer[j]-i+1;
            }
        }
        if(count<ans){
            ans=count;
            real=i;
        }
    }
    printf("%d %d",real,ans);
}
// 3
// 4 6 5
// 3 2 4

// 2 3


// 3
// 5 8 6
// 2 4 1

// 1 4


// 5
// 7 9 6 8 5
// 4 5 1 3 5

// 3 9


// 5
// 9 4 5 6 8
// 4 4 5 1 3

// 3 8


// 6
// 2 2 2 2 2 2
// 1 2 1 2 1 2

// 1 3
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,i;
    scanf("%d",&n);
    vector <int> layer(n);
    vector <int> hole(n);
    int mnlayer=INT_MAX;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&layer[i]);
        mnlayer=min(mnlayer,layer[i]);
    }
    for(i=0;i<n;i++) scanf("%d",&hole[i]);
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