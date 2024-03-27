/*
TASK: SEGMENT
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int i,j,k,n,m,upnum=0,downnum=0;
    cin >> n >> m;
    char up[3][n*3],down[3][m*3];
    for(i=0;i<3;i++) for(j=0;j<n*3;j++) cin >> up[i][j];
    for(i=0;i<3;i++) for(j=0;j<m*3;j++)cin >> down[i][j];
    i=0;
    for(j=0;j<n*3;j+=3)
    {
        if(up[i][j]==' '&& up[i][j+1]==' ' && up[i][j+2]==' '&& up[i+1][j]==' ' && up[i+1][j+1]==' ' && up[i+1][j+2]=='|' && up[i+2][j]==' ' && up[i+2][j+1]==' ' && up[i+2][j+2]=='|')
        {
            upnum = upnum*10 + 1;
        }
        else if(up[i][j]==' '&& up[i][j+1]=='_' && up[i][j+2]==' '&& up[i+1][j]==' ' && up[i+1][j+1]=='_' && up[i+1][j+2]=='|' && up[i+2][j]=='|' && up[i+2][j+1]=='_' && up[i+2][j+2]==' ')
        {
            upnum = upnum*10 + 2;
        }
        else if(up[i][j]==' '&& up[i][j+1]=='_' && up[i][j+2]==' '&& up[i+1][j]==' ' && up[i+1][j+1]=='_' && up[i+1][j+2]=='|' && up[i+2][j]==' ' && up[i+2][j+1]=='_' && up[i+2][j+2]=='|')
        {
            upnum = upnum*10 + 3;
        }
        else if(up[i][j]==' '&& up[i][j+1]==' ' && up[i][j+2]==' '&& up[i+1][j]=='|' && up[i+1][j+1]=='_' && up[i+1][j+2]=='|' && up[i+2][j]==' ' && up[i+2][j+1]==' ' && up[i+2][j+2]=='|')
        {
            upnum = upnum*10 + 4;
        }
        else if(up[i][j]==' '&& up[i][j+1]=='_' && up[i][j+2]==' '&& up[i+1][j]=='|' && up[i+1][j+1]=='_' && up[i+1][j+2]==' ' && up[i+2][j]==' ' && up[i+2][j+1]=='_' && up[i+2][j+2]=='|')
        {
            upnum = upnum*10 + 5;
        }
        else if(up[i][j]==' '&& up[i][j+1]=='_' && up[i][j+2]==' '&& up[i+1][j]=='|' && up[i+1][j+1]=='_' && up[i+1][j+2]==' ' && up[i+2][j]=='|' && up[i+2][j+1]=='_' && up[i+2][j+2]=='|')
        {
            upnum = upnum*10 + 6;
        }
        else if(up[i][j]==' '&& up[i][j+1]=='_' && up[i][j+2]==' '&& up[i+1][j]==' ' && up[i+1][j+1]==' ' && up[i+1][j+2]=='|' && up[i+2][j]==' ' && up[i+2][j+1]==' ' && up[i+2][j+2]=='|')
        {
            upnum = upnum*10 + 7;
        }
        else if(up[i][j]==' '&& up[i][j+1]=='_' && up[i][j+2]==' '&& up[i+1][j]=='|' && up[i+1][j+1]=='_' && up[i+1][j+2]=='|' && up[i+2][j]=='|' && up[i+2][j+1]=='_' && up[i+2][j+2]=='|')
        {
            upnum = upnum*10 + 8;
        }
        else if(up[i][j]==' '&& up[i][j+1]=='_' && up[i][j+2]==' '&& up[i+1][j]=='|' && up[i+1][j+1]=='_' && up[i+1][j+2]=='|' && up[i+2][j]==' ' && up[i+2][j+1]=='_' && up[i+2][j+2]=='|')
        {
            upnum = upnum*10 + 9;
        }
        else if(up[i][j]==' '&& up[i][j+1]=='_' && up[i][j+2]==' '&& up[i+1][j]=='|' && up[i+1][j+1]==' ' && up[i+1][j+2]=='|' && up[i+2][j]=='|' && up[i+2][j+1]=='_' && up[i+2][j+2]=='|')
        {
            upnum = upnum*10 + 3;
        }
    }
    for(j=0;j<n*3;j+=3)
    {
        if(down[i][j]==' '&& down[i][j+1]==' ' && down[i][j+2]==' '&& down[i+1][j]==' ' && down[i+1][j+1]==' ' && down[i+1][j+2]=='|' && down[i+2][j]==' ' && down[i+2][j+1]==' ' && down[i+2][j+2]=='|')
        {
            downnum = downnum*10 + 1;
        }
        else if(down[i][j]==' '&& down[i][j+1]=='_' && down[i][j+2]==' '&& down[i+1][j]==' ' && down[i+1][j+1]=='_' && down[i+1][j+2]=='|' && down[i+2][j]=='|' && down[i+2][j+1]=='_' && down[i+2][j+2]==' ')
        {
            downnum = downnum*10 + 2;
        }
        else if(down[i][j]==' '&& down[i][j+1]=='_' && down[i][j+2]==' '&& down[i+1][j]==' ' && down[i+1][j+1]=='_' && down[i+1][j+2]=='|' && down[i+2][j]==' ' && down[i+2][j+1]=='_' && down[i+2][j+2]=='|')
        {
            downnum = downnum*10 + 3;
        }
        else if(down[i][j]==' '&& down[i][j+1]==' ' && down[i][j+2]==' '&& down[i+1][j]=='|' && down[i+1][j+1]=='_' && down[i+1][j+2]=='|' && down[i+2][j]==' ' && down[i+2][j+1]==' ' && down[i+2][j+2]=='|')
        {
            downnum = downnum*10 + 4;
        }
        else if(down[i][j]==' '&& down[i][j+1]=='_' && down[i][j+2]==' '&& down[i+1][j]=='|' && down[i+1][j+1]=='_' && down[i+1][j+2]==' ' && down[i+2][j]==' ' && down[i+2][j+1]=='_' && down[i+2][j+2]=='|')
        {
            downnum = downnum*10 + 5;
        }
        else if(down[i][j]==' '&& down[i][j+1]=='_' && down[i][j+2]==' '&& down[i+1][j]=='|' && down[i+1][j+1]=='_' && down[i+1][j+2]==' ' && down[i+2][j]=='|' && down[i+2][j+1]=='_' && down[i+2][j+2]=='|')
        {
            downnum = downnum*10 + 6;
        }
        else if(down[i][j]==' '&& down[i][j+1]=='_' && down[i][j+2]==' '&& down[i+1][j]==' ' && down[i+1][j+1]==' ' && down[i+1][j+2]=='|' && down[i+2][j]==' ' && down[i+2][j+1]==' ' && down[i+2][j+2]=='|')
        {
            downnum = downnum*10 + 7;
        }
        else if(down[i][j]==' '&& down[i][j+1]=='_' && down[i][j+2]==' '&& down[i+1][j]=='|' && down[i+1][j+1]=='_' && down[i+1][j+2]=='|' && down[i+2][j]=='|' && down[i+2][j+1]=='_' && down[i+2][j+2]=='|')
        {
            downnum = downnum*10 + 8;
        }
        else if(down[i][j]==' '&& down[i][j+1]=='_' && down[i][j+2]==' '&& down[i+1][j]=='|' && down[i+1][j+1]=='_' && down[i+1][j+2]=='|' && down[i+2][j]==' ' && down[i+2][j+1]=='_' && down[i+2][j+2]=='|')
        {
            downnum = downnum*10 + 9;
        }
        else if(down[i][j]==' '&& down[i][j+1]=='_' && down[i][j+2]==' '&& down[i+1][j]=='|' && down[i+1][j+1]==' ' && down[i+1][j+2]=='|' && down[i+2][j]=='|' && down[i+2][j+1]=='_' && down[i+2][j+2]=='|')
        {
            downnum = downnum*10 + 3;
        }
    }
    cout << downnum+upnum ;
}