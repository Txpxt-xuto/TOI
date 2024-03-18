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
    bool isValid(string s) {
        stack<char> parentheses;
        cin >> s;
        for(int i=0;i<parentheses.size();i++)
        {
            if(s[i]=="{")
            {
                parentheses.push(s[i]);
            }
            else if(parentheses.top()=="{" && s[i]=="}")
            {
                parentheses.pop();
            }
            else if(parentheses.top()=="[" && s[i]=="]")
            {
                parentheses.pop();
            }
            else if(parentheses.top()=="(" && s[i]==")")
            {
                parentheses.pop();
            }
            i++;
        }
        if(parentheses.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
int main()
{

}