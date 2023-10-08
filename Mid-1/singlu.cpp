#include<iostream>
using namespace std;


class node
{
    public:
    int data;
    node *next;

    node(int value)
    {
        data =value;
        next=NULL;
    }
};

void insertTail(node *&head, int value)
{
    node *n =new node(value);
    if(head==NULL)
    {
        head=n;
        return;
    }
    node *temp =head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=n;

}
void inseertHead(node *&head, int value)
{
    node *n =new node(value);
    n->next=head;
    head=n;

}
void deleteAny(node *&head, int value)
{
    node *temp=head;
    int count=0;
    while(temp->next!=NULL)
    {
        if(count==value-1)
        {
            cout<<"here"<<count;
            temp->next=temp->next->next;

        }
        temp=temp->next;
        count++;

    }

}
void update(node *&head, int key, int value)
{
    node* temp=head;
    int count=0;
    while(temp->next!=NULL){
        if(key==count)
        {
            temp->data=value;
        }
        temp=temp->next;
        count++;
    }
}
void reverse(node *&head)
{
    node *temp=head;
    node *next=NULL;
    node *prev=NULL;
    while (temp!=NULL)
    {
        next=temp->next;
        temp->next=prev;
        prev=temp;
        temp=next;
    }
    head=prev;
}
void deleteLastNode(node *&head)
{
    node* temp=head;
    while(temp->next->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=NULL;
}
void display(node *head)
{
    node *temp=head;
    while (temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}
int main()
{
    node *head=NULL;
    insertTail(head,1);
    insertTail(head,2);
    insertTail(head,7);
    insertTail(head,4);
    inseertHead(head,5);
    display(head);
    deleteAny(head,3);
    cout<<"Delete 3rd Node:"<<endl;
    display(head);
    cout<<"Last node delted:"<<endl;
    deleteLastNode(head);
    display(head);
    cout<<"Updated node:"<<endl;
    update(head,1,51);
    display(head);

    reverse(head);
    display(head);

}