/*
TASK: jail
LANG: C
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
/*#include <stdio.h>
int main()
{
    int i,j=0,k=1,n,m;
    scanf("%d %d",&n,&m);
    int Jail[n];
    for(i=0;i<n;i++) Jail[i]=0;
    i=0;
    while(j!=n)
    {
        if(i>=n) i-=n;
        if(k%m==0 && Jail[i]==0) 
        {
            printf("%d ",i+1);
            Jail[i]=1;
            k++;
            j++;
        } 
        else if(Jail[i]!=1) k++;
        i++;
    }
}*/

#include <stdio.h>
int main()
{
    int i=0,j,k;
    char Kemija[100];
    scanf("%s",kemija);
    while(i>=0)
    {
        if(Kemaji[i]=='e' && Kemaji[i+2]==Kemaji[i] && Kemaji[i+1]=='p') 
        {
            Kemaji[i+1]='';
            Kemaji[i+2]='';
        }
        i++
    }
    printf("%s",Kemaji);
}

#include <stdio.h>
int main()
{
    int i=0,j=0;
    char Kemija[100];
    fgets(Kemija, sizeof(Kemija), stdin);
    while(i>=0)
    {
        if((Kemija[i]=='e') && (Kemija[i+2]=='e') && (Kemija[i+1]=='p'))
        {
            Kemija[i+1]='-';
            Kemija[i+2]='-';
        }
        else if((Kemija[i]=='a') && (Kemija[i+2]=='a') && (Kemija[i+1]=='p'))
        {
            Kemija[i+1]='-';
            Kemija[i+2]='-';
        }
        else if((Kemija[i]=='i') && (Kemija[i+2]=='i') && (Kemija[i+1]=='p'))
        {
            Kemija[i+1]='-';
            Kemija[i+2]='-';
        }
        else if((Kemija[i]=='o') && (Kemija[i+2]=='o') && (Kemija[i+1]=='p'))
        {
            Kemija[i+1]='-';
            Kemija[i+2]='-';
        }
        else if((Kemija[i]=='u') && (Kemija[i+2]=='u') && (Kemija[i+1]=='p'))
        {
            Kemija[i+1]='-';
            Kemija[i+2]='-';
        }
        i++;
        if(Kemija[i]==0 && Kemija[i+1]==0) i=-5;
    }
    while(j>=0)
    {
        if(Kemija[j]!='-') printf("%c",Kemija[j]);
        j++;
        if(Kemija[j]==0 && Kemija[j+1]==0) j=-5;
    }
}
