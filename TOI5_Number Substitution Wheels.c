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
    char input[3],password[256],code[256];
    scanf("%s\n%s",&input,&password);
    for(i=0;i<strlen(password);i++)
    {
        code[i]=password[i];
    }
    
    for(i=0;i<strlen(password);i++)
    {
        for(j=0;j<3;j++)
        {
            password[i]=((input[j]+password[i]-'0'-'0'-2)%9+1)+'0';
            if(j==0|j==2)
            {
                input[j] = ((input[j]+code[i]-'0'-'0'-1)%9+1)+'0';
            }
            else
            {
                input[j]=((input[j]+7-'0')%9+1)+'0';
            }
        }
    }
    for(i=0;i<strlen(password);i++)
    {
        printf("%c",password[i]);
    }
}