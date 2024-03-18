/*
TASK: express
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <iostream>
#include <string>
#include <stack>
#include <queue>
using namespace std;
class Solution {
public:
    bool isValid(string s)
    {
        stack<char> a;
        for (char &c : s)
        {
            if(c=='{' || c=='[' || c=='(')
            {
                a.push(c);
            }
            if((c=='}' && a.top()=='{')||(c==']' && a.top()=='[')||(c==')' && a.top()=='('))
            {
                a.pop();
            }
        }
        if(a.empty())
        {
            return true;
        }
        return false;
    }
    
};
int main()
{

}