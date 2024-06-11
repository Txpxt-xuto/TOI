/*
TASK: location.c
LANG: C
COMPILER: VS code
AUTHOR: Tapat Toungsakul
CENTER: Home
*/ 
#include <stdio.h>
int main()
{
    int m, n, k, a, i, j;
    scanf("%d%d", &m, &n);
    scanf("%d", &k);
    int map[m][n];
    for(i=0;i<m;i++) for(j=0;j<n;j++) scanf("%d", &map[i][j]);
    int ans = 0;
    for(i=0;i<=m-k;i++) 
    {
        for(j=0;j<=n-k;j++) 
        {
            int temp = 0;
            for(a=i;a<i+k;a++) for(b=j;b<j+k;b++) temp += map[a][b];
            if(temp > ans) ans = temp;
        }
    }
    printf("%d", ans);
}