/*
TASK: WORD
Lang: C
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <stdio.h>
int main()//กุลีแห่งท่าเรือ//
{
    long long i,k,N,M;
    scanf("%d %d",&M,&N);
    long long Labor[M+3];
    for(k=1;k<=M;k++) scanf("%d",&Labor[k]);
    long long k = 1, j = 1000000LL * N;
    while(k<j)
    {
    long long mid = (k + j) / 2;
    long long all = 0;
    for (i=1;i<=M;i++) all += mid / Labor[i];
    if (all>=N) j = mid;
    else k = mid + 1;
    }
    printf("%lld",k);
}
