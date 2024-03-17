/*
TASK: SKYLINE
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/

#include <iostream>
using namespace std;
int main()
{
    int i,j,n,building[256];
	for(i=0;i<256;i++)
	{
        building[i]=0;
    }
	cin >> n;
	for(int i=0;i<n;i++)
	{
		int l,h,r;
		cin>>l>>h>>r;
		for(j=l;j<r;j++)
		{
			if(building[j]<h)
            {
                building[j]=h;
            }
		}
	}
	for(i=1;i<256;i++)
	{
		if(building[i-1]!=building[i])
		{
			cout << i << " " << building[i] << " ";
		}
	}
}