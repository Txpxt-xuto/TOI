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
        k = (password[i] - '0');
        for(j=0;j<3;j++)
        {
            k = (input[j]+k-2)%9 + 1;
            if(j==0 || j==2)
            {
                input[j]= ((input[j])+code[j]-1)%9+1;
            }
        }
        input[1] = input[1]==1?9:input[1]-1;
        printf("%d",k);
    }
}