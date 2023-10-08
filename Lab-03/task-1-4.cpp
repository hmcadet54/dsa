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

//===================================================================== task 01(a)
void insert_at_tail(node *&head, int value)
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
}

//======================================================================== task 01(b)
void insert_at_head(node *&head, int value)
{
    node *n = new node(value);
    n->next = head;
    head = n;
}

//========================================================================== task 02
void insert_node_after(node *&head, int value, int after)
{
    node *n = new node(value);
    node *temp = head;
    while (temp->data != after)
    {
        temp = temp->next;
    }
    n->next = temp->next;
    temp->next = n;
}

// =============================================================================task 03
void delete_last_node(node *&head)
{
    node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = NULL;
}
void delete_any_node(node *&head, int value)
{
    node *temp = head;
    while (temp->next->data != value)
    {
        temp = temp->next;
    }
    temp->next = temp->next->next;
}

// ================================================================================task 04
void update_node(node *&head, int value, int new_value)
{
    node *temp = head;
    while (temp->data != value)
    {
        temp = temp->next;
    }
    temp->data = new_value;
}

void display(node *head)
{
    node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    node *head = NULL;

    insert_at_tail(head, 1);
    insert_at_tail(head, 2);
    insert_at_tail(head, 3);
    insert_at_tail(head, 4);
    insert_at_tail(head, 5);
    display(head);
    cout<<endl;

    cout<<"After Inserting at head"<<endl;
    insert_at_head(head, 0);
    insert_at_head(head, -1);
    display(head);
    cout<<endl;


    cout<<"After Inserting at 6th and 7th node"<<endl;
    insert_node_after(head, 6, 5);
    insert_node_after(head, 7, 6);
    display(head);
    cout<<endl;


    cout<<"After Deleting last node"<<endl;
    delete_last_node(head);
    display(head);
    cout<<endl;


    cout<<"After deleting the element=3 node"<<endl;
    delete_any_node(head, 3);
    display(head);
    cout<<endl;


    cout<<"After updating the element=2 node with 10"<<endl;
    update_node(head, 2, 10);
    display(head);
    return 0;
}
