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
    int input[3];
    char password[256];
    scanf("%s\n%s",&input,&password);
    int i,j,k;
    for(i=0;i<strlen(password);i++)
    {
        printf("%d ",input[0]);
        printf("%d ",input[1]);
        printf("%d ",input[2]);
        printf("%d ",input[3]);
        input[0]=(input[0]+(password[i]-'0'))%10;
        input[1]=(input[0]+(password[i]-'0'))%10;
        input[2]=(input[1]+(password[i]-'0'))%10;
        printf("%d ",input[0]);
        printf("%d ",input[1]);
        printf("%d ",input[2]);

    }
}