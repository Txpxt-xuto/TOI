/*
TASK: PATTERN
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <stdio.h>
int main()
{
    int i,j,k,x,y,z,N,recheak;
    scanf("%d",&N);
    int P[N],Q[N],R[N];
    for(i=0;i<N;i++)
    {
        scanf("%d %d %d",&P[i],&Q[i],&R[i]);
    }
    //จัดลำดับค่าจากน้อยไปมาก
    for(k=0;k<N;k++)
    {
        for(i=0;i<(N-1);i++)
        {
            if(P[i]>P[i+1])
            {
                j=P[i];
                P[i]=P[i+1];
                P[i+1]=j;
                j=Q[i];
                Q[i]=Q[i+1];
                Q[i+1]=j;
                j=R[i];
                R[i]=R[i+1];
                R[i+1]=j;
            }
            if(P[i]==P[i+1])
            {
                if(Q[i]>Q[i+1])
                {
                    j=P[i];
                    P[i]=P[i+1];
                    P[i+1]=j;
                    j=Q[i];
                    Q[i]=Q[i+1];
                    Q[i+1]=j;
                    j=R[i];
                    R[i]=R[i+1];
                    R[i+1]=j;
                }
            }
        }
    }
    //เริ่มทำลายผ้า
    for(i=0;i<N;i++)
    {
        if(i==0)//กรณีเริ่มต้น
        {
            for(j=1;j<Q[i];j++)
            {
                printf("o");
            }
            for(j=Q[i];j<R[i]+Q[i];j++)
            {
                printf("x");
            }
            recheak=P[i];
        }
        else if(recheak==P[i])//กรณียังอยู่บรรทัดเดิม
        {
            for(j=Q[i-1]+R[i-1];j<Q[i];j++)
            {
                printf("o");
            }
            for(j=Q[i];j<R[i]+Q[i];j++)
            {
                printf("x");
            }
        }
        else if(recheak!=P[i])//กรณีขี้นบรรทัดใหม่
        {
            for(j=R[i-1]+Q[i-1];j<=70;j++)
            {
                printf("o");
            }
            printf("\n");
            for(j=1;j<Q[i];j++)
            {
                printf("o");
            }
            for(j=Q[i];j<R[i]+Q[i];j++)
            {
                printf("x");
            }
            recheak=P[i];
        }
    }
    //ปิดจบในบรรทัดสุดท้าย
    for(j=R[N-1]+Q[N-1];j<=70;j++)
        {
            printf("o");
        }
}