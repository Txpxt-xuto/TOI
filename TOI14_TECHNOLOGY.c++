/*
TASK: technology.cpp
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/

void solve() {
    int n, k, t; 
    cin >> n >> k >> t;
    rep(i, 1, n) 
    {
        int l, m; 
        cin >> l >> m;
        lvl[l].pb(i);
        rep(j, 1, m) 
        { 
        int x; 
        cin >> x; 
        before[i].pb(x); 
        }

}