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
void swapNodes(node *&head, int key1, int key2)
{
    node *temp = head;
    int count = 1;
    node *temp1;
    node *temp2;
    while (count != key2)
    {
        temp = temp->next;
        count++;
        if (count == key1)
        {
            temp1 = temp;
        }
        else if (count == key2)
        {
            temp2 = temp;
        }
    }
    temp1->prev->next = temp2;
    temp2->prev->next = temp1;
    node *temp3 = temp1->prev;
    temp1->prev = temp2->prev;
    temp2->prev = temp3;
    temp3 = temp1->next;
    temp1->next = temp2->next;
    temp2->next = temp3;
}
void Display(node *anynode)
{
    node *temp = anynode;
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
    Inserttail(head, 56);
    Inserttail(head, 3);
    Inserttail(head, 78);
    Inserttail(head, 5);
    Display(head);
    swapNodes(head, 2, 4);
    Display(head);
    return 0;
}