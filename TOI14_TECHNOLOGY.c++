/*
TASK: technology.cpp
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include<bits/stdc++.h>
#include <stack>
using namespace std;
int main()
{
    string inp;
    cin >> inp;
    stack<int> stack, operationn;
    int ind = 0, x, s1, s2
    int x, s1, s2;
    char i;
    for(j=0;j<inp.length();++j)
    {
        i = inp[j];
        if(i == '1' || i == '2' || i == '3')
        {
            if(i == '1') ind = 1;
            else if(i == '2') ind = 2;
            else if(i == '3') ind = 3;
            if(operationn.empty()) operationn.push(ind);
            else
            {
                x = operationn.top();
                operationn.pop();
                while(ind <= x)
                {
                    if(stack.size() <= 1) break;
                    s1 = stack.top();
                    stack.pop();
                    s2 = stack.top();
                    stack.pop();
                    stack.push((s1+s2)*(100 + 2*(1<<x))/100);
                    if(operationn.empty()) break;
                    x = operationn.top();
                    operationn.pop();
                }
                operationn.push(x);
                operationn.push(ind);
            }
        }
        else if(i == '[') operationn.push(-1);
        else if(i == ']')
        {
            while(operationn.top() != -1)
            {
                x = operationn.top();
                s1 = stack.top();
                stack.pop();
                s2 = stack.top();
                stack.pop();
                stack.push((s1+s2)*(100 + 2*(1<<x))/100);
                operationn.pop();
            }
            operationn.pop();
        }
        else stack.push(20);
    }
    while(stack.size() != 1)
    {
        ind = operationn.top();
        operationn.pop();
        s1 = stack.top();
        stack.pop();
        s2 = stack.top();
        stack.pop();
        stack.push((s1+s2)*(100 + 2*(1 << ind))/100);
    }
    cout << stack.top();
}