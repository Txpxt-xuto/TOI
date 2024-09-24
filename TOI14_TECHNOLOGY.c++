/*
TASK: technology.cpp
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <bits/stdc++.h>
using namespace std;
int sol(int a, int b, int c)
{
    if (c == 3) return ((a + b) * 16) / 100 + a + b;
    if (c == 2) return ((a + b) * 8) / 100 + a + b;
    if (c == 1) return ((a + b) * 4) / 100 + a + b;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int i, j, len;
    int temp, ans;
    string s;
    stack<char> operand;
    stack<int> price;
    cin >> s;
    len = s.length();
    for (i = 0; i < len; i++)
    {
        if ('A' <= s[i] && s[i] <= 'Z')
        {
            price.push(20);
        }
        else if (s[i] == '[')
        {
            operand.push(0);
        }
        else if (s[i] == ']')
        {
            while (operand.top() != 0)
            {
                temp = price.top();
                price.pop();
                ans = sol(price.top(), temp, operand.top());
                price.pop();
                price.push(ans);
                operand.pop();
            }
            operand.pop();
        }
        else
        {
            if (!operand.empty() && operand.top() != 0 && operand.top() >= s[i] - '0')
            {
                while (!operand.empty() && operand.top() != 0 &&operand.top() >= s[i] - '0')
                {
                    temp = price.top();
                    price.pop();
                    ans = sol(price.top(), temp, operand.top());
                    price.pop();
                    price.push(ans);
                    operand.pop();
                }
                operand.push(s[i] - '0');
            }
            else
            {
                operand.push(s[i] - '0');
            }
        }
    }
    while (price.size() != 1)
    {
        temp = price.top();
        price.pop();
        ans = sol(price.top(), temp, operand.top());
        price.pop();
        price.push(ans);
        operand.pop();
    }
    cout << price.top();
}