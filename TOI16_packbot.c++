#include<bits/stdc++.h>

using namespace std;

string s;

void insrt(char p){
    for(int i=0;i<s.length();i++){
        if(s[i]==p){

            if(s[i]== '3')
                s[i] = '@';
            if(s[i]=='2')
                s[i]='#';
            if(s[i]=='1')
                s[i]='$';

            int cnt=0;
            for(int j=i-1;j>=0;j--){
                if(s[j] == ']')
                    cnt++;
                else if(s[j] == '[')
                    cnt--;

                if(cnt == 0){
                    if(isalpha(s[j]))
                        s[j]='*';
                    s.insert(j,"[");
                    i++;
                    break;
                }
            }

            for(int j=i+1;j<s.length();j++){
                if(s[j] == '[')
                    cnt++;
                else if(s[j] == ']')
                    cnt--;

                if(cnt == 0){
                    if(isalpha(s[j]))
                        s[j]='*';
                    s.insert(j+1,"]");
                    i++;
                    break;
                }
            }
        }
    }
}

int calculate(string ss){
    stack<char> st;
    int total=0;
    for(int i=0;i<s.length();i++){
        st.push(s[i]);
        if(st.top() == ']'){
            string tmp;
            st.pop();
            while(!st.empty() && st.top()!='['){
                tmp += st.top();
                st.pop();
            }
            reverse(tmp.begin(),tmp.end());
            st.pop();
            float num1=0,num2=0,op=0;
            bool done = false;
            for(j=0;j<tmp.length();j++)
            {
                if(isdigit(tmp[j]))
                {
                    if(!done)
                    {
                        num1*=10;
                        num1+= tmp[j]-'0';
                    }
                    else
                    {
                        num2*=10;
                        num2+= tmp[j]-'0';
                    }
                }
                else
                {
                    done = true;
                    if(tmp[j]=='@') op = 0.16f;
                    if(tmp[j]=='#') op = 0.08f;
                    if(tmp[j]=='$') op = 0.04f;
                }
            }
            total = floor((num1+num2)*op);
            total+=num1;
            total+=num2;
            if(st.empty()) return total;
            string tmp2;
            while(total != 0)
            {
                tmp2 += (total%10) + '0';
                total/=10;
            }
            reverse(tmp2.begin(),tmp2.end());
            for(k=0;k<tmp2.length();k++) st.push(tmp2[k]);
        }
    }
}
int main()
{
    int i;
    cin >> s;
    insrt('3');
    insrt('2');
    insrt('1');
    for(i=0;i<s.length();i++)
    {
        if(s[i] == '*')
        {
            s[i] = '2';
            s.insert(i+1,"0");
        }
    }
    string tmp = s;
    cout << calculate(tmp);
}
