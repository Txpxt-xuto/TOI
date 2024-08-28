#include <iostream>
#include <stack>
#include <queue>
using namespace std;
int i;
int main(){
    string s;
    cin >> s;
    stack<int> num, operate;
    float opr, num1, num2;
    for(i=0; i<s.size(); i++)
    {
        if(s[i] > 64 && s[i] < 91) num.push(20);
        else if(s[i] == '[') operate.push(-1);
        else if(s[i] == ']')
        {
            while(!operate.empty() && operate.top() != -1)
            {
                opr = operate.top();
                operate.pop();
                num1 = num.top();
                num.pop();
                num2 = num.top();
                num.pop();
                num.push(int((num1 + num2) * (100+opr) /100));
            }
            operate.pop();
        }
        else 
        {
            int curr;
            if(s[i] == '1') curr = 4;
            else if(s[i] == '2') curr = 8;
            else if(s[i] == '3') curr = 16;
            while(!operate.empty() && curr <= operate.top())
            {
                opr = operate.top();
                operate.pop();
                num1 = num.top();
                num.pop();
                num2 = num.top();
                num.pop();
                num.push(int((num1 + num2) * (100+opr) /100));
            }
            operate.push(curr);
        }
    }
    while(!operate.empty())
    {
        opr = operate.top();
        operate.pop();
        num1 = num.top();
        num.pop();
        num2 = num.top();
        num.pop();
        num.push(int((num1 + num2) * (100+opr) /100));
    }
    cout << num.top();
    return 0;
}