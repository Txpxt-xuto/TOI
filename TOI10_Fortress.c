/*
TASK: fortress.c
LANG: C
AUTHOR: 
CENTER: 
*/
#include <stdio.h>
int main() 
{
  int z[20],n[20];
  for(int i=0;i<20;i++)
  {
    if(z[i]<=200000000||n[i]<=100000000)
    {
      scanf("%d %d",&z[i],&n[i]);
      if(n[i]*2>z[i]||z[i]%2!=0||n[i]==0||z[i]==0||n[i]<(z[i]-n[i]*2)/2) printf("%d\n",0);
      else printf("%d\n",n[i]-((z[i]-n[i]*2)/2)+1);
    }
  }
}