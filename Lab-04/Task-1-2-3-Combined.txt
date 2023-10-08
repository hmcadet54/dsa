


//====================================================Circular linked list============================================

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









//====================================================Doubly linked list============================================


#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node *prev;

    node(int value)
    {
        data = value;
        next = NULL;
        prev = NULL;
    }
};

void Inserttail(node *&head, int value)
{
    node *n = new node(value);
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
    n->prev = temp;
}
void insertHead(node *&head, int value)
{
    node *n = new node(value);
    n->next = head;
    head->prev = n;
    head = n;
}

void InsertAtPos(node *&head, int value, int pos)
{
    node *n = new node(value);
    node *temp = head;
    int count = 1;
    while (count != pos)
    {
        temp = temp->next;
        count++;
    }
    n->next = temp->next;
    temp->next = n;
    n->prev = temp;
    n->next->prev = n;
}

void DeleteAnyNode(node *&head, int pos)
{
    node *temp = head;
    int count = 1;
    while (count != pos)
    {
        temp = temp->next;
        count++;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    delete temp;
}

void Display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "<->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
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

    insertHead(head, 0);
    Display(head);

    InsertAtPos(head, 10, 3);
    Display(head);

    DeleteAnyNode(head, 3);
    Display(head);
    return 0;
}








//====================================================Circular Doubly linked list============================================


#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node *prev;

    node(int value)
    {
        data = value;
        next = NULL;
        prev = NULL;
    }
};


void instertAtAtil(node *&head, int value)
{
    node *n = new node(value);
    if (head == NULL)
    {
        n->next = n;
        n->prev = n;
        head = n;
        return;
    }
    node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->prev = temp;
    n->next = head;
    head->prev = n;
}
void insertHead(node *&head, int value)
{
    node *n = new node(value);
    if (head == NULL)
    {
        instertAtAtil(head, value);
        return;
    }
    node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->prev = temp;
    n->next = head;
    head->prev = n;
    head = n;
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
    n->prev = temp;
    n->next->prev = n;
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
    temp->next->prev = temp;
    delete todelete;
}
void display(node *head)
{
    node *temp = head;
    do
    {
        cout << temp->data << "->";
        temp = temp->next;
    } while (temp != head);
    cout << "NULL" << endl;
}

int main()
{
    node *head = NULL;
    insertHead(head, 1);
    insertHead(head, 2);
    insertHead(head, 3);
    insertHead(head, 4);
    display(head);
    cout<<"Inserting 5 at tail"<<endl;
    instertAtAtil(head, 5);
    display(head);
    cout<<"Inserting 6 at position 3"<<endl;
    InsertAtPos(head, 6, 3);
    display(head);
    cout<<"Deleting node at position 3"<<endl;
    DeleteAnyNode(head, 3);
    display(head);
    return 0;
}