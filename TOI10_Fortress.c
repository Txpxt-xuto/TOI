/*
TASK: fortress.c
LANG: C
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <stdio.h>
int main() 
{
  int dp[21],n[21];
  for(int i=0;i<20;i++)
  {
    if(dp[i]<=200000000||n[i]<=100000000)
    {
      scanf("%d %d",&dp[i],&n[i]);
      if(n[i]*2>dp[i] || dp[i]%2!=0 || n[i]==0 || (dp[i]==0) || (n[i]<(dp[i]-n[i]*2)/2)) printf("%d\n",0);
      else printf("%d\n",n[i]-((dp[i]-n[i]*2)/2)+1);
    }
  }
}