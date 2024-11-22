/*
TASK: technology.cpp
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/

    {
        int l, m; cin >> l >> m;
        lvl[l].pb(i);
        rep(j, 1, m){ int x; cin >> x; before[i].pb(x); }
    }
    int mx = 0;
    function<bool(int)> upgrade = [&](int i)
    {
        if(mark[i]==2) return 1;
        if(mark[i]==1) return 0;
        if(t==0) return 0;
        mark[i] = 1; t--;
        trav(x, before[i]) if(!upgrade(x)) return 0;
        mark[i] = 2;
        return 1;
    };
    rep(i, 1, k)
    {
        trav(x, lvl[i]) if(!upgrade(x)) return void(cout << (i==1?-1:i-1) << nl);
    }  
    cout << k << nl;
int main(int argc, char* argv[])
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t = 1;
    while (t--) { solve(); }
    return 0;
}