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

class queue
{
    public:
    node *front;
    node *back;

    queue()
    {
        front=NULL;
        back=NULL;
    }

    void enqueue(int x)
    {
        node *n =new node(x);
        if (front==NULL)
        {
            back=front=n;
            return;
        }

        back->next=n;
        back=n;

    }

    void dequeue()
    {
        if(front==NULL)
        {
            cout<<"Queue is underflow"<<endl;
            return;
        }
        node *temp=front;
        front=front->next;
        delete temp;
    }

    int peek()
    {
        if(front==NULL)
        {
            cout<<"Queue is underflow"<<endl;
            return -1;
        }
        return front->data;

    }
    bool empty()
    {
        if(front==NULL)
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
        node *temp=front;
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        
    }

};

int main()
{
    
}

