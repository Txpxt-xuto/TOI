/*
TASK: MOUNTAIN
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <stdio.h>
int main() 
{
    int n,i,j;
    scanf("%d",&n);
    int len = 0, hei = 0, s[n], h[n];
    char map[hei][len];
    for(i=0;i<n;i++) 
    {
        scanf("%d%d",&s[i],&h[i]);
        s[i]--;
        len = len > s[i] - 1 + 2*h[i] ? len : s[i] - 1 + 2*h[i];
        hei = hei > h[i] ? hei : h[i];
    }
    len++;
    for(i=0;i<hei;i++) for(j=0;j<len;j++) map[i][j] = '.';
    for(i=0;i<n;i++) 
    {
        int m = s[i], p = hei-1;
        while(m <= s[i] + h[i] - 1) 
        {
            if (map[p][m] == '.') map[p][m] = '/';
            else if (map[p][m] == '\\') map[p][m] = 'v';
            for (j=p+1;j<hei;j++) map[j][m] = 'X';
            m++;
            p--;
        }
        p++;
        while(m <= s[i] + 2*(h[i]) - 1) 
        {
            if (map[p][m] == '.') map[p][m] = '\\';
            else if (map[p][m] == '/') map[p][m] = 'v';
            for (j=p+1;j<hei;j++) map[j][m] = 'X';
            m++;
            p++;
        }
    }
    for(i=0;i<hei;i++) 
    {
        for(j=0;j<len;j++) printf("%c", map[i][j]);
        printf("\n");
    }
}