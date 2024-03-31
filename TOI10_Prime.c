/*
TASK: prime.c 
LANG: C
AUTHOR: Tapat Toungsakul
CENTER: Home
*/ 
#include<stdio.h>
int prime[7368789];
int main()
{
    long long n;
    scanf(" %lld",&n);
    //if(n==500000) printf("7368787");
    //else if(n==1) printf("2");
    //else if(n==2) printf("3");
    int cou=1;
    for(long long i=2;i<7368788;i++)
    {
        if(cou==n && prime[i]==0)
        {
            printf("%lld",i);
            return 0;
        }
        else if(cou<n && prime[i]==0)
        {
            for(long long j=i*2;j<7368788;j+=i){ prime[j]=1; }
            cou++;
        }
    }
}
