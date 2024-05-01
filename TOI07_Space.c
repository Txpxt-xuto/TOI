#include <stdio.h>
void generatebit(int d, string)
{
    if(n==d) 
    {
        for(int i=d-1;i>=0;i--) {
            if(s[i]=='0') 
            {
                cout<<s<<" "; 
                s[i]='1'
                ; cout<<s<<"\n"
                ; s[i]='0';
            }
        }
    }
    else
    {
        solve(n+1,s+'0');
        solve(n+1,s+'1');
    }
}
int main()
{
    int d;
    scanf("%d",&d);
    generatebit(d);
}