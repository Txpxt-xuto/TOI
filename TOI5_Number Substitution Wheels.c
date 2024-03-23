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
    char input[3],password[256];
    scanf("%s\n%s",&input,&password);
    int i,j,k;
    for(i=0;i<strlen(password);i++)
    {
        printf("%c ",input[0]);
        printf("%c ",input[1]);
        printf("%c \n",input[2]);
        input[0]=((input[0]-'0')+(password[i]-'0'))%10;
        input[1]=((input[0]-'0')+(password[i]-'0'))%10;
        input[2]=((input[1]-'0')+(password[i]-'0'))%10;
        printf("%d \n",password[i]-'0');
        printf("%d ",input[0]);
        printf("%d ",input[1]);
        printf("%d ",input[2]);

    }
}