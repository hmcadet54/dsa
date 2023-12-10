#include<iostream>
using namespace std;
#define n 100

class stack
{
    int *array;
    int top;
    public:

    stack()
    {
        array=new int[n];
        top=-1;
    }

    void push(int x)
    {
        if(top==n-1)
        {
            cout<<"stack is overflow"<<endl;
            return;
        }
        top++;
        array[top]=x;
    }

    void pop()
    {
        if(top==-1)
        {
            cout<<"No element to pop"<<endl;
        }
        top--;
    }
    int peak()
    {
        if(top==-1)
        {
            cout<<"No element in stack"<<endl;
        }
        return array[top];
    }

    bool empty()
    {
        if(top==-1)
        {
            return true;
        }
        else{
            return false;
        }
    }

    void display()
    {
        if(top==-1)
        {
            cout<<"No element in stack"<<endl;
            return;
        }
        int m=top;
        for(int i=0;i<=m;i++)
        {
            cout<<array[i]<<" ";
        }

    }

};

int main()
{

    stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.display();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    cout<<s.empty();
    s.display();


}