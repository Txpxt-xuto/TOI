/*
TASK: ROMAN
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <stdio.h>
int main()
{
    int d,w,y,z,i=0,v=0,x=0,l=0,c=0;
    scanf("%d",&d);
    while (d>=1)
    {
        w=d/100;
        y=d/10-(d/100)*10;
        z=d%10;
        //ร้อย
        if(w>=1)
        {
            c+=w;
        }
        //สิบ
        if(y!=0)
        {
            if(y==9)
            {
                x+=1;
                c+=1;
            }
            if(y<=8 && y>=5)
            {
                x+=y-5;
                l+=1;
            }
            if(y==4)
            {
                x+=1;
                l+=1;
            }
            if(y<=3 && y>=1)
            {
                x+=y;
            }
        }
        //หน่วย
        if(z!=0)
        {
            if(z==9)
            {
                x+=1;
                i+=1;
            }
            else if(z<=8 && z>=5)
            {
                i+=z-5;
                v+=1;
            }
            else if(z==4)
            {
                v+=1;
                i+=1;
            }
            else if(z<=3 && z>=1)
            {
                i+=z;
            }
        }
        d--;
    }
    printf("%d %d %d %d %d\n",i,v,x,l,c);
}