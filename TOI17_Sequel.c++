#include <bits/stdc++.h>

using namespace std;
const int B=400;
int niza[100002];
int dp[100002][B+4];

int main()
{
    int n,q;
    cin>>n>>q;
    for (int i=0;i<n;i++) cin>>niza[i];

    for (int i=n-1;i>=0;i--)
    {
        for (int skok=1;skok<B;skok++)
        {
            dp[i][skok]=niza[i];
            if (skok+i<n) dp[i][skok]+=dp[i+skok][skok];
        }
    }

    while(q--)
    {
        int l,m,r;
        cin>>l>>m>>r;
        l--;
        r--;
        int odg=0,x=(r-l)/m;
        int desno = l+x*m;
        if (m<B)
        {
            //cout<< "levo = "<<l<<" desno = "<<desno<<endl;
            //cout<< "dodava "<<dp[l][m]<<endl;
            odg=dp[l][m];
            if (desno+m<n)
            {
                //cout<< "odzema "<<dp[desno+m][m]<<endl;
                odg-=dp[desno+m][m];
                //cout<< "ali dodava "<<niza[desno]<<endl;
                //odg+=niza[desno];
            }
        }
        else
        {
            for (int i=l;i<=r;i+=m) odg+=niza[i];
        }

        cout<<odg<<" ";
    }

    return 0;
}