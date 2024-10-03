/*
TASK: technology.cpp
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int qs[500][500];
inline int f(int i, int j){if(i>=0 && j>=0) return qs[i][j]; return 0;}
signed main()
{
    int i,j,tc;
	for(tc = 0; tc<2; ++tc)
    {
		memset(qs, 0, sizeof(qs));
		int m, n, t;
        scanf("%d %d %d",&m,&n,&t);
		for(i,j;t--;)
        {
            scanf("%d %d", &i, &j);
            qs[i][j] = 1;
        }
		for(int i = 0; i<m; ++i)
        {
			for(j=0;j<n;++j) qs[i][j] += f(i-1, j) + f(i, j-1) - f(i-1, j-1);
		}
		bool ch = false;
		for(k=min(m, n);k;--k)
        {
			for(i=k-1;i<m;++i)
            {
				for(j=k-1;j<n;++j)
                {
					int outer = f(i, j) - f(i-k, j) - f(i, j-k) + f(i-k, j-k);
					int inner = f(i-1, j-1) - f(i-k+1, j-1) - f(i-1, j-k+1) + f(i-k+1, j-k+1);
					if(outer == inner)
                    {
                        printf("%d\n",k);
                        ch = true;
                        break;
                    }
				}
				if(ch) break;
			}
			if(ch) break;
		}
		if(ch) continue;
		puts("0");
	}	
}