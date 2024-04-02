/*
TASK: SEGMENT
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <bits/stdc++.h>
using namespace std;

map<string, int> mp 
{
    {"     |  |", 1}, 
    {" _  _||_ ", 2}, 
    {" _  _| _|", 3}, 
    {"   |_|  |", 4}, 
    {" _ |_  _|", 5}, 
    {" _ |_ |_|", 6}, 
    {" _   |  |", 7}, 
    {" _ |_||_|", 8}, 
    {" _ |_| _|", 9}, 
    {" _ | ||_|", 0}
};

string a[3],b[3];
long long suma,sumb;

int main() 
{
	int n,m; cin >> n >> m;
	cin.ignore();
	for(int i=0;i<3;i++) getline(cin, a[i]);
	for(int i=0;i<3;i++) getline(cin, b[i]);
	for(int i=0;i<4*n-1;i+=4) 
    {
		string temp;
		for(int j=0;j<9;j++) temp += a[j/3][i+j%3];
		suma *= 10;
		suma += mp[temp];
	}
	for(int i=0;i<4*m-1;i+=4) 
    {
		string temp;
		for(int j=0;j<9;j++) temp += b[j/3][i+j%3];
		sumb *= 10;
		sumb += mp[temp];
	}
	cout << suma + sumb;
}