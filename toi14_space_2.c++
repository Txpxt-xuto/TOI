/*
TASK: space.cpp
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <stdio.h>
int arr[4][4], tmp[10], table[10], num_x[] = {1, 0, -1, 0, 1, 1, -1, -1}, num_y[] = {0, 1, 0, -1, 1, -1, 1, -1};
int n, m;
double min = 2000000000;

int in_range(int x, int a) {
    if(x >= 0 && x <= a) {
        return 1;
    }
    return 0;
}

void run(int index) {
    int i;
    if(index == n * m) {
        /**
        for(i = 0; i < n*m; i++) {
            printf("%d ", table[i]);
        }
        printf("\n");
        /**/
        int j, x, y;
        double c, sum = 0, land[4][4];
        for(i=0;i<n;i++)
		{
            for(j=0;j<m;j++) land[i][j] = 1.0*arr[i][j];
        }
        for(i=0;i<n*m;i++)
		{
            sum += land[table[i] / m][table[i] % m];
            c = land[table[i] / m][table[i] % m]/10;
            land[table[i] / m][table[i] % m] = 0;
            x = table[i] / m;
            y = table[i] % m;
            for(j=0;j<8;j++)
			{
                if(in_range(x+num_x[j], n) && in_range(y+num_y[j], m)) land[x+num_x[j]][y+num_y[j]] += c;
            }
        }
        if(sum < min) min = sum;
        return;
    }
    for(i=0;i<n*m;i++)
	{
        if(tmp[i] == 1) continue;
        tmp[i]++;
        table[index] = i;
        run(index+1);
        tmp[i]--;
    }
}
int main()
{
    int i, j, k;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++)
	{
        for(j=0;j<m;j++) scanf("%d", &arr[i][j]);
    }
    run(0);
    printf("%.2lf", min);
    return 0;
}