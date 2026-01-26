/*
TASK: PATTERN
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <stdio.h>
char PATTERN[50010][100] = {};
int i,j,k,x,y,z;
int max = 0;
int main()
{
    int N;
	scanf("%d",&N);
	for(i=1;i<=50000;i++)
    {
		for(j=1;j<=70;j++) PATTERN[i][j] = 'o';
	}
    for(i=0;i<N;i++)
	{
		scanf("%d %d %d",&x,&y,&z);
		for(j=0;j<z;j++) PATTERN[x][y+j] = 'x';
		if(x > max) max = x;
	}
    for(i=1;i<=max;i++)
    {
		for(j=1;j<=70;j++) printf("%c",PATTERN[i][j]);
		printf("\n");
	}
}
