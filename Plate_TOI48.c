/*
TASK: PLATE
LANG: C
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <stdio.h>
int main()
{
    int Nc,Ns,i,j,k,y,z;
    scanf("%d %d",&Nc,&Ns);
    int Class[Ns][Ns],x[Ns];
    char come,Idcome[Ns],array[Ns];
    for(i=0;i<Ns;i++)
    {
        for(j=0;j<2;j++)
        {
            scanf("%d",&Class[i][j]);
        }
    }
    y=0;
    j=0;
    k=0;
    while(k==0)
    {
        scanf("%s",&come);
        if(come=='E')
        {
            scanf("%s",&Idcome);
            for(i=0;i<Ns;i++)
            {
                if(Idcome==Class[i][1])
                {
                    x[j]=Class[i][0];
                    break;
                }
            }
            array[j]=Idcome;
            j++;
            for(i=0;i<=j;i++)
            {
                printf("%d %s\n",x[i],array[i]);
            }
        }
        else if(come=='D')
        {
        }
        else if(come=='X')
        {
            k=1;
        }
    }
    for(i=0;i<j;i++)
    {
        printf("%d %s\n",x[i],array[i]);
    }
}