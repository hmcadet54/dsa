#include <iostream>

using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};

void insertAtTail(node *&head, int val)
{
    node *n = new node(val);
    if (head == NULL)
    {
        head = n;
        return;
    }

    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}
void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    // cout<<"NULL"<<endl;
}
void reverse(node *&head)
{
    node *prevptr = NULL;
    node *currentptr = head;
    node *nextptr;

    while (currentptr != NULL)
    {
        nextptr = currentptr->next;
        currentptr->next = prevptr;

        prevptr = currentptr;
        currentptr = nextptr;
    }
    head = prevptr;
}

void extractalt(node *&head)
{
    node *newlist = NULL;
    node *altnodes = NULL;
    node *temp = head;

    while (temp != NULL && temp->next != NULL)
    {
        insertAtTail(altnodes, temp->next->data);
        temp = temp->next->next;
    }
    temp = head;
    while (temp != NULL)
    {

        insertAtTail(newlist, temp->data);
        if (temp->next != NULL)
        {
            temp = temp->next->next;
        }
        else
        {
            break;
        }
    }
    reverse(altnodes);
    temp = newlist;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = altnodes;
    head = newlist;

}

int main()
{
    node *head = NULL;
    insertAtTail(head, 10);
    insertAtTail(head, 4);
    insertAtTail(head, 9);
    insertAtTail(head, 1);
    insertAtTail(head, 3);
    insertAtTail(head, 5);
    insertAtTail(head, 9);
    insertAtTail(head, 4);
    display(head);

    cout << endl;
    extractalt(head);
    display(head);
}