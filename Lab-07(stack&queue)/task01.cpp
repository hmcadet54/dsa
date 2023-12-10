#include<iostream>
#include <cstring>
using namespace std;
#define n 100

class stack
{
    char *array;
    int top;
    public:

    stack()
    {
        array=new char[n];
        top=-1;
    }

    void push(char x)
    {
        if(top==n-1)
        {
            cout<<"stack is overflow"<<endl;
            return;
        }
        top++;
        array[top]=x;
    }

    char pop()
    {
        if(top==-1)
        {
            cout<<"No element to pop"<<endl;
        }
        top--;
        char x=array[top+1];
        return x;
    }
    char peak()
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
    bool checkpal(string& a, string& b)
    {
        return a==b;
    }

};

int main()
{

    stack s;
    string pal;
    cout<<"Enter string to check: ";
    cin>>pal;
    for (int i=0;i<pal.size();i++)
    {
        s.push(pal[i]);
    }
    string checkPal="";
    for (int i=0;i<pal.size();i++)
    {
        checkPal+=s.pop();

    }
    cout<<pal<<endl;
    cout<<checkPal<<endl;
    if(s.checkpal(pal,checkPal))
    {
        cout<<"String is palindrome"<<endl;
    }
    else
    {
        cout<<"String is not palindrome"<<endl;
    }
}