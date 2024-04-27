/*
TASK: pair
LANG: C
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <stdio.h>
double sum=0,fw[100001];
int n;
void createtree(double *fwtree,int n)
{
    for(int i=1; i<=n; i++)
    {
        int j=(i&-i)+i;
        if(j<=n) fwtree[j]+=fwtree[i];
    }
}
double prefixsum(double *fwtree,int i)
{
    double sum=0;
    while(i)
    {
        sum+=fwtree[i];
        i&=~(i&-i);
    }
    return sum;
}
double rangesum(double *fwtree,int a,int b)
{
    return prefixsum(fwtree,b)-prefixsum(fwtree,a-1);
}
void add(double *fwtree,int n,int i,int d)
{
    while(i<=n)
    {
        fwtree[i]+=d;
        i+=i&-i;
    }
}
void update(double *fwtree,int n,int i,int val)
{
    int d=val-rangesum(fwtree,i,i);
    add(fwtree,n,i,d);
}

void merge(int *arr,int l,int m,int r)
{
    int n1=m-l+1,n2=r-m,p[n1],q[n2];
    for(int i=0; i<n1; i++) p[i]=arr[l+i];
    for(int i=0; i<n2; i++) q[i]=arr[m+1+i];
    int i=0,j=0,k=0;
    while(i<n1 && j<n2)
    {
        if(p[i]>q[j])
        {
            sum+=rangesum(fw,l+i,m)+(q[j]*(m-l-i+1));
            arr[l+k++]=q[j++];
        } 
        else arr[l+k++]=p[i++];
    }
    while(i<n1) arr[l+k++]=p[i++];
    while(j<n2) arr[l+k++]=q[j++];
    for(int i=l; i<=r; i++) update(fw,n,i,arr[i]);
}
void mergesort(int *arr,int l,int r)
{
    if(l<r)
    {
        int m=l+(r-l)/2;
        mergesort(arr,l,m);
        mergesort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}
int main()
{
    scanf("%d",&n);
    int arr[n+1],a,b;
    arr[0]=0;
    for(int i=0; i<n; i++)
    {
        scanf("%d %d",&a,&b);
        arr[b]=fw[b]=a;
    }
    createtree(fw,n);
    mergesort(arr,1,n);
    printf("%.0lf",sum);
    return 0;
}