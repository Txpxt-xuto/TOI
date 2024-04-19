#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,q,x,idx;
    cin >> n >> q;
    int A[n],ansl[n],ansr[n];
    vector <int> L;
    vector <int> R;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    for (int i = 0; i < n; i++)
    {
        idx = lower_bound(L.begin(),L.end(),A[i])-L.begin();
        if (idx == L.size())
        {
            L.push_back(A[i]);
        }
        else
        {
            A[i] = idx;
        }
        ansl[i] = idx;
    }
    for (int i = n-1; i >= 0; i--)
    {
        idx = lower_bound(R.begin(),R.end(),A[i])-R.begin();
        if (idx == R.size())
        {
            R.push_back(A[i]);
        }
        else
        {
            A[i] = idx;
        }
        ansr[i] = idx;
    }
    for (int i = 0; i < q; i++)
    {
        cin >> x;
        cout << min(ansl[x],ansr[x]) << "\n";
    }
    return 0;
}