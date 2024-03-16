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
            if(x[j]<a[i] && x[j]<b[i])
			{	if(a[i]>b[i])
                {
					x[j]=b[i];
                }
				else
                {
					x[j]=a[i];
                }
            }
			else if(x[j]>a[i] && x[j]>b[i])
            {
				if(a[i]>b[i])
                {
					x[j]=a[i];
                }
				else
                {
					x[j]=b[i];
                }
            }
        }
    }
    for(j=0;j<k;j++)
    {
        printf("%c",x[j]);
    }
}