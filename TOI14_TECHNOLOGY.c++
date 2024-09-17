/*
TASK: technology.cpp
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> v[105];
int a[105],dp[105][2];
priority_queue<tuple<int,int,int,int>,vector<tuple<int,int,int,int>>,greater<tuple<int,int,int,int>>> pq;
int main()
{
}
/*
#include <bits/stdc++.h>
using namespace std;
typedef long long ii;

stack<ii> S;
stack<int> Operand;

void calc(){
    int x = Operand.top();
    ii a=S.top();S.pop();
    ii b=S.top();S.pop();
    if(x==1)S.push((a+b)*104/100);
    if(x==2)S.push((a+b)*108/100);
    if(x==3)S.push((a+b)*116/100);
}

int main(){
    string s;cin>>s;
    for(char &c:s){
        //cout<<c;
        if(isalpha(c)){
            S.push(20);
            continue;
        }
        else if(c=='['){
            Operand.push(-1);
        }
        else if(c==']'){
            while(Operand.top()!=-1){
                calc();
                Operand.pop();
            }
            Operand.pop();
        }
        else{
            while(!Operand.empty()&&Operand.top()>=(c-'0')){
                calc();
                Operand.pop();
            }
            Operand.push(c-'0');
        }
    }

    while(!Operand.empty())calc(),Operand.pop();
    
    cout<<S.top();


    return 0;
}
 */