#include<iostream>
using namespace std;


class node
{
    public:
    int data;
    node *next;
    node(int value)
    {
        data= value;
        next=NULL;
    }

};
class stack
{
    node *top;
    public:
    stack()
    {
        top=NULL;
    }
    void push(int x)
    {
        node *n =new node(x);
        n->next=top;
        top=n;
    }
    void pop()
    {
        if(top!=NULL)
        {
            node *temp=top;
            top=top->next;
            delete temp;
        }
    }
    bool empty()
    {
        if(top!=NULL)
        {
            return true;
        }
        else{
            return false;
        }
    }

    void display()
    {
        if(top!=NULL)
        {
            node *temp=top;
            while(temp!=NULL)
            {
                cout<<temp->data<<"->";
                temp=temp->next;
            }
            cout<<"NULL"<<endl;
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
    
}