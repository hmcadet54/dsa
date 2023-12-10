#include <iostream>
#include <stack>

using namespace std;

int prec(char c)
{
    if (c == '^')
    {
        return 3;
    }
    else if (c == '*' || c == '/')
    {
        return 2;
    }
    else if (c == '+' || c == '-')
    {
        return 1;
    }
    else
    {
        return -1;

    }
        
}

string infixTOpostfix(string infix)
{
    stack<char> stc;
    string postfix="";

    for (int i = 0; i < infix.length(); i++)
    {
        if (infix[i] >= 'a' && infix[i] <= 'z' || infix[i] >= 'A' && infix[i] <= 'Z')
        {
            postfix += infix[i];
        }
        else if (infix[i] == '(')
        {
            stc.push(infix[i]);
        }
        else if (infix[i] == ')')
        {
            while (!stc.empty() && stc.top() != '(')
            {
                postfix += stc.top();
                stc.pop();
            }
            if (!stc.empty() && stc.top() == '(') // check if stack is not empty and top is opening parenthesis
            {
                stc.pop(); // pop the opening parenthesis
            }
        }
        else
        {
            while (!stc.empty() && prec(stc.top()) >= prec(infix[i])) // change > to >=
            {
                postfix += stc.top();
                stc.pop();
            }
            stc.push(infix[i]);
        }
    }
    while (!stc.empty())
    {
        postfix += stc.top();
        stc.pop();
    }
    return postfix;
}

int main()
{
    cout << infixTOpostfix("((a+b)*c)-d");
}