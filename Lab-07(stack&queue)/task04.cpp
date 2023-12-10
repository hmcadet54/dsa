#include <iostream>
#include <algorithm>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int value)
    {
        data = value;
        next = NULL;
    }
};

class queue
{
public:
    node *front;
    node *back;

    queue()
    {
        front = NULL;
        back = NULL;
    }

    void push(int x)
    {
        node *n = new node(x);
        if (front == NULL)
        {
            back = front = n;
            return;
        }

        back->next = n;
        back = n;
    }

    void pop()
    {
        if (front == NULL)
        {
            return;
        }
        node *temp = front;
        front = front->next;
        delete temp;
    }

    int top()
    {
        if (front == NULL)
        {
            return -1;
        }
        return front->data;
    }
    bool empty()
    {
        if (front == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void display()
    {
        node *temp = front;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};
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
    queue myqueue;
    string postfix = "";

    for (int i = 0; i < infix.length(); i++)
    {
        if (infix[i] >= 'a' && infix[i] <= 'z' || infix[i] >= 'A' && infix[i] <= 'Z')
        {
            postfix += infix[i];
        }
        else if (infix[i] == '(')
        {
            myqueue.push(infix[i]);
        }
        else if (infix[i] == ')')
        {
            while (!myqueue.empty() && myqueue.top() != '(')
            {
                postfix += myqueue.top();
                myqueue.pop();
            }
            if (!myqueue.empty() && myqueue.top() == '(') 
            {
                myqueue.pop(); 
            }
        }
        else
        {
            while (!myqueue.empty() && prec(myqueue.top()) >= prec(infix[i])) 
            {
                postfix += myqueue.top();
                myqueue.pop();
            }
            myqueue.push(infix[i]);
        }
    }
    while (!myqueue.empty())
    {
        postfix += myqueue.top();
        myqueue.pop();
    }

    return postfix;
}

int main()
{
    string s="((a+b)*c)-d";

    cout<<infixTOpostfix(s);    
}