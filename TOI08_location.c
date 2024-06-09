/*
TASK: location.c
LANG: C
COMPILER: VS code
AUTHOR: Tapat Toungsakul
CENTER: Home
*/ 
#include <stdio.h>

int main( ) {
    int m, n;
    scanf("%d%d", &m, &n);
    int k;
    scanf("%d", &k);
    int map[m][n];
    for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) scanf("%d", &map[i][j]);
    int ans = 0;
    for (int i = 0; i <= m-k; i++) {
        for (int j = 0; j <= n-k; j++) {
            int temp = 0;

            for (int a = i; a < i+k; a++) {
                for (int b = j; b < j+k; b++) {
                    temp += map[a][b];
                }
            }

            if (temp > ans) {
                ans = temp;
            }
        }
    }

    printf("%d", ans);
}