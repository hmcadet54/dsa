#include <iostream>
#include <stack>
using namespace std;

bool openbracket(char c)
{
    return (c == '(');
}

bool closebracket(char c)
{
    return (c == ')');
}

int precedence(char c)
{
    switch (c)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    case '(':
    case ')':
        return 4;
    default:
        return -1;
    }
}

bool operand(char c)
{
    if ((c == '+') || (c == '-') || (c == '/') || (c == '*') || (c == '^') || (c == '(') || (c == ')'))
        return false;
    return true;
}

bool associativity(char c)
{
    if ((c == '+') || (c == '-') || (c == '/') || (c == '*'))
        return 0; // left to right
    return 1;     // right to left
}

int main()
{
    stack<char> s;
    // char infix[] = "K+L-M*N+(O^P)*W/U/V*T+Q";
    char infix[] = "((a+b)*c)-d";

    char postfix[16];
    int i = 0;
    int j = 0;
    while (infix[i] != '\0')
    {
        if (operand(infix[i]))
            postfix[j++] = infix[i++];
        else
        {
            if (s.empty())
                s.push(infix[i++]);
            else if (openbracket(s.top()))
                s.push(infix[i++]);
            else if (closebracket(infix[i]))
            {
                while (!openbracket(s.top()))
                {
                    postfix[j++] = s.top();
                    s.pop();
                }
                s.pop();
                i++;
            }

            else if (precedence(s.top()) < precedence(infix[i]))
                s.push(infix[i++]);
            else
            {
                while (!(s.empty()) && (!operand(infix[i])) && (precedence(s.top()) >= precedence(infix[i])))
                {
                    if (precedence(s.top()) == precedence(infix[i]))
                    {
                        if (associativity(infix[i]))
                            s.push(infix[i++]);
                        else
                        {
                            postfix[j++] = s.top();
                            s.pop();
                        }
                    }
                    else
                    {
                        postfix[j++] = s.top();
                        s.pop();
                    }
                }
                s.push(infix[i++]);
            }
        }
    }
    while (!s.empty())
    {
        postfix[j++] = s.top();
        s.pop();
    }

    cout<<postfix;
    return 0;
}