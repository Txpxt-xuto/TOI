/*
TASK: KEY
LANG: C
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <stdio.h>
int main()
{
    int l,k;
    scanf("%d %d",&l,&k);
    char a[l],b[l],x[k];
    scanf("%s",&a);
    scanf("%s",&b);
    scanf("%s",&x);
    int i,j;
    for(j=0;j<k;j++)
    {
        for(i=0;i<l;i++)
        {
            if(a[i]<=x[j]<=b[i] || a[i]>=x[j]>=b[i])
            {
                x[j]=x[j];
            }
            else if(x[j]<=a[i]<=b[i] || x[j]>=a[i]>=b[i])
            {
                x[j]=a[i];
            }
            else if(x[j]<=b[i]<=a[i] || x[j]>=b[i]>=a[i])
            {
                x[j]=b[i];
            }
        }
    }
    for(j=0;j<k;j++)
    {
        printf("%c",x[j]);
    }
}