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
        if(mark[i]==2) return 1;
        if(mark[i]==1) return 0;
        mark[i] = 1; t--;

int main(int argc, char* argv[])
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t = 1;
    while (t--) { solve(); }
    return 0;
}