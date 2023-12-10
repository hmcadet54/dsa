#include <iostream>
#include <cstring>
#include <sstream>
#include <cmath>

using namespace std;

class node
{
public:
    string data;
    node *next;
    node *prev;

    node(string value)
    {
        data = value;
        next = prev = NULL;
    }
};

class stack
{
    node *top;

public:
    stack()
    {
        top = NULL;
    }

    void push(string x)
    {
        node *n = new node(x);
        if (top)
        {
            n->next = top;
            top->prev = n;
        }
        top = n;
    }

    void pop()
    {
        if (top != NULL)
        {
            node *temp = top;
            top = top->next;
            if (top)
            {
                top->prev = NULL;
            }
            delete temp;
        }
    }
 

    bool empty()
    {
        return top == NULL;
    }
    string peek()
    {
        if (!empty())
        {
            return top->data;
        }
        return "";
    }

    void display()
    {
        if (top != NULL)
        {
            node *temp = top;
            while (temp != NULL)
            {
                cout << temp->data;
                temp = temp->next;
            }
            cout << endl;
        }
    }
    int converion(string a)
    {
        stringstream left(a);
        int l = 0;
        left >> l;
        return l;
    }

    int calculate()
    {
        node *temp = top;
        int sum = 0;
        while (temp != NULL)
        {
            if (temp->data == "+")
            {
                sum += converion(temp->prev->data) + converion(temp->next->data);
            }
            if (temp->data == "(")
            {
                int five=converion(temp->prev->data);
                while (temp->data != ")")
                {
                    if (temp->data == "+")
                    {
                        if (converion(temp->prev->data) + converion(temp->next->data) == 0)
                        {
                            sum-=1*five;
                        }
                    }
                    temp = temp->next;
                }
            }
            temp = temp->next;
        }
        return sum;
    }
};

int main()
{
    stack s;
    s.push("1");
    s.push("+");
    s.push(")");
    s.push("0.5");
    s.push("+");
    s.push("0.5");
    s.push("(");
    s.push("5");
    s.push("-");
    s.push("13");
    s.push("+");
    s.push("12");
    s.push("=");
    s.push("x");
    cout << endl;
    s.display();
    cout << endl;

    int sum = s.calculate();
    string strsum=to_string(sum);
    s.push(strsum);
    cout<<"The Answer of given Equation is :"<<s.peek();
}