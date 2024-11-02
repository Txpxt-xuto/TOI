/*
TASK: technology.cpp
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <bits/stdc++.h>
using namespace std;
using pi = pair <int, int>;
char ar1[1010], ar2[1010];
int l1, l2;
bool key(string s)
{
    queue <pi> q;
    vector < vector <bool>> visited(l1 + 2, vector <bool> (l2 + 2, false));
    q.push({0, 0});
    while(q.size() > 0)
    {
        int a1 = q.front().first;
        int a2 = q.front().second;
        q.pop();
        if(a1 == l1 and a2 == l2) return true;
        if(a1 + a2 >= s.size() or visited[a1][a2]) continue;
        visited[a1][a2] = true;
        if(!visited[a1+1][a2] and (s[a1+a2] == ar1[a1] or a2 == l2 and s[a1+a2] == ar1[a1])) q.push({a1+1, a2});
        if(!visited[a1][a2+1] and (s[a1+a2] == ar2[a2] or a1 == l1 and s[a1+a2] == ar2[a2])) q.push({a1, a2+1});
    }
    return false;
}
int main()
{
    scanf("%s",ar1);
    scanf("%s",ar2);
    l1 = strlen(ar1);
    l2 = strlen(ar2);
}