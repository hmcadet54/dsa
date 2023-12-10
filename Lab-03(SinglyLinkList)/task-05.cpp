#include <iostream>
#include <typeinfo>
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
void all_even_first_all_OddE(node *&head)
{
    node *temp = head;
    node *EvenS = NULL;
    node *EvenE = NULL;
    node *OddS = NULL;
    node *OddE = NULL;

    while (temp != NULL)
    {
        if (temp->data % 2 == 0)
        {
            if (EvenS == NULL)
            {
                EvenS = temp;
                EvenE = EvenS;
            }
            else
            {
                EvenE->next = temp;
                EvenE = EvenE->next;
            }
        }
        else
        {
            if (OddS == NULL)
            {
                OddS = temp;
                OddE = OddS;
            }
            else
            {
                OddE->next = temp;
                OddE = OddE->next;
            }
        }
        temp = temp->next;
    }
    if (OddS == NULL || EvenS == NULL)
    {
        return;
    }
    EvenE->next = OddS;
    OddE->next = NULL;
    head = EvenS;
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
    insert_at_tail(head, 1);
    insert_at_tail(head, 4);
    insert_at_tail(head, 1);
    display(head);
    return 0;
}
