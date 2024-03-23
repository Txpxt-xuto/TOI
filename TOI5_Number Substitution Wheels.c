/*
TASK: NSW
LANG: C
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <stdio.h>
#include <string.h>
int main()
{
    int i,j,k;
    int input[5],code[5];
    char password[260];
    scanf("%s",&password);
    for(i=0;i<3;i++)
    {
        input[i]=password[i]-'0';
        code[i]=input[i];
    }
    scanf("%s",&password);
    for(i=0;i<strlen(password);i++)
    {
        int dp = (password[i] - '0');
        dp = (input[0]+dp-2)%9 + 1;
        dp = (input[1]+dp-2)%9 + 1;
        dp = (input[2]+dp-2)%9 + 1;

        input[0]= ((input[0])+code[0]-1)%9+1;
        input[2]= ((input[2])+code[2]-1)%9+1;
        input[1] = input[1]==1?9:input[1]-1;
        printf("%d",dp);
    }
}