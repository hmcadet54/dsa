//Circular linked list

#include <iostream>
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



void insertHead(node *&head, int value)
{
    node *n = new node(value);
    if(head==NULL)
    {
        n->next=n;
        head=n;
        return;
    }
    node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
    head = n;
}
void Inserttail(node *&head, int value)
{
    node *n = new node(value);
    if (head == NULL)
    {
        insertHead(head, value);
        return;
    }
    node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->next=head;
}
void InsertAtPos(node *&head, int value, int pos)
{
    node *n = new node(value);
    node *temp = head;
    int count = 1;
    while (count != pos-1)
    {
        temp = temp->next;
        count++;
    }
    n->next = temp->next;
    temp->next = n;
}
void DeleteAnyNode(node *&head, int pos)
{
    node *temp = head;
    int count = 1;
    while (count != pos-1)
    {
        temp = temp->next;
        count++;
    }
    node *todelete = temp->next;
    temp->next = temp->next->next;
    delete todelete;
}


void Display(node *head)
{
    node *temp = head;
    while( temp->next!=head)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << temp->data << endl;
}

int main()
{
    node *head = NULL;
    Inserttail(head, 1);
    Inserttail(head, 2);
    Inserttail(head, 3);
    Inserttail(head, 4);
    Inserttail(head, 5);
    Display(head);
    InsertAtPos(head, 6, 3);
    Display(head);

    DeleteAnyNode(head, 3);
    Display(head);

    return 0;
}