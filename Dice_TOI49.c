/*
TASK: DICE
LANG: C
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <stdio.h>
#include <string.h>
int main()
{
    int i,j,k,n,m,x;
    scanf("%d",&n);
    char word[n][1001];
    for(i=0;i<n;i++)
    {
        scanf("%s",&word[i]);
    }
    for(i=0;i<n;i++)
    {
        int dice[6] = {1, 2, 3, 4, 5, 6};
		m = strlen(word[i]);
		for(j=0;j<m;j++){
			if (word[i][j] == 'F')
            {
				x = dice[0];
				dice[0] = dice[4];
				dice[4] = dice[5];
				dice[5] = dice[1];
				dice[1] = x;
			} 
            else if (word[i][j] == 'B')
            {
				x = dice[0];
				dice[0] = dice[1];
				dice[1] = dice[5];				
				dice[5] = dice[4];
				dice[4] = x;
			} 
            else if (word[i][j] == 'L')
            {
				x = dice[0];
				dice[0] = dice[3];
				dice[3] = dice[5];
				dice[5] = dice[2];
				dice[2] = x;				
			} 
            else if (word[i][j] == 'R')
            {
				x = dice[0];
				dice[0] = dice[2];
				dice[2] = dice[5];
				dice[5] = dice[3];
				dice[3] = x;				
			}
            else if (word[i][j] == 'C')
            {
				x = dice[1];
				dice[1] = dice[3];
				dice[3] = dice[4];								
				dice[4] = dice[2];
				dice[2] = x;
			} 
            else if (word[i][j] == 'D')
            {
				x = dice[1];
				dice[1] = dice[2];
				dice[2] = dice[4];
				dice[4] = dice[3];
				dice[3] = x;				
			}
		}
        printf("%d ",dice[1]);
    }
}