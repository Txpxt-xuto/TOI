/*
TASK: treasure
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <iostream>
#include <iomanip>
#include <bits/stdc++.h>
using namespace std;
string treasure;
int main()
{
    int i=1,j;
    float x=0,y=0,k;
    while(true)
    {
		cin >> treasure;
		double num = 0;
        //หาเลขหน้าตัวเลขอักษร
		while(true)
        {
			if(treasure[0] >= '0' && treasure[0] <= '9')
            {
				num = num*10 + (treasure[0] -'0');
				treasure.erase(0,1);//ลบตัวเลขจากกลุ่มคำ
			}
			else break;
        }
        int len = treasure.length();
        //กรณีของทิศต่างๆ
        if(treasure == "*")
        {
            k=sqrt((y*y)+(x*x));
            cout << fixed << setprecision(3) << x << " " << fixed << setprecision(3) << y << endl << fixed << setprecision(3) << k;
        }
        else if(len==1)
        {
            if(treasure =="N") y+=num;
            else if(treasure =="S") y-=num;
            else if(treasure =="E") x+=num;
            else if(treasure =="W") x-=num;
        }
        else if(len!=1)
        {
            if(treasure =="NE"){y+=num;x+=num;} 
            else if(treasure =="SE"){y-=num;x+=num;}
            else if(treasure =="NW"){y+=num;x-=num;}
            else if(treasure =="SW"){y-=num;x-=num;}
        }
    }
}