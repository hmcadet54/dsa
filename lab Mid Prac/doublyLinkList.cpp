#include<iostream>
using namespace std;


class node 
{
    public:
    int data;
    node * prev;
    node * next;
    node(int value)
    {
        data=value;
        prev=NULL;
        next=NULL;
    }
};
void Head( node *&head, int value)
{
    node *n =new node(value);
    n->next=head;
    if(head != NULL) {
        head->prev=n;
    }
    head=n;
}

void Tail(node *&head, int value)
{
    node* n =new node(value);
    node* temp=head;
    if (head==NULL)
    {
        Head(head, value);
        return;
    }
    while(temp->next!=NULL)
    {
        temp=temp->next;

    }
    temp->next=n;
    n->prev=temp;

}
void lastNode(node *&head)
{
    node* temp=head;
    while(temp->next->next!=NULL)
    {
        temp=temp->next;
    }
    delete temp->next;
    temp->next=NULL;
}
void display(node *head)
{
    node *temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}
void AnyNode(node *&head, int pos)
{
    node *temp =head;
    int count=0;
    while(count!=pos)
    {
        temp=temp->next;
        count++;
    }
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
}

void UpdateNyNode(node *&head, int pos, int value)
{
    node* n=new node(value);
    node* temp=head;
    int count=0;
    while(count!=pos)
    {
        temp=temp->next;
        count++;
    }
    temp->data=n->data;
}

void InsrtAtpos(node *&head, int pos, int value)
{
    node* temp=head;
    node* n=new node(value);
    int count=0;
    while(count!=pos)
    {
        temp=temp->next;
        count++;
    }
    n->next=temp->next;
    n->prev=temp;
    temp->next=n;
    
}

int main()
{
    node *head=NULL;
    Tail(head,3);
    Tail(head,5);
    Tail(head,7);
    Tail(head,9);
    Tail(head,4);
    display(head);
    // lastNode(head);
    // // display(head);
    // AnyNode(head,2);
    // // display(head);
    // UpdateNyNode(head,3,15);
    // display(head);
    InsrtAtpos(head,2,18);
    display(head);
    return 0;
}