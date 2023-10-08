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

// task 01(a)
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

// task 01(b)
void insert_at_head(node *&head, int value)
{
    node *n = new node(value);
    n->next = head;
    head = n;
}

// task 02
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

// task 03
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

// task 04
void update_node(node *&head, int value, int new_value)
{
    node *temp = head;
    while (temp->data != value)
    {
        temp = temp->next;
    }
    temp->data = new_value;
}

// task 05
void all_even_first_all_odd_end(node *&head)
{
    node *temp = head;
    node *even_start = NULL;
    node *even_end = NULL;
    node *odd_start = NULL;
    node *odd_end = NULL;

    while (temp != NULL)
    {
        if (temp->data % 2 == 0)
        {
            if (even_start == NULL)
            {
                even_start = temp;
                even_end = even_start;
            }
            else
            {
                even_end->next = temp;
                even_end = even_end->next;
            }
        }
        else
        {
            if (odd_start == NULL)
            {
                odd_start = temp;
                odd_end = odd_start;
            }
            else
            {
                odd_end->next = temp;
                odd_end = odd_end->next;
            }
        }
        temp = temp->next;
    }
    if (odd_start == NULL || even_start == NULL)
    {
        return;
    }
    even_end->next = odd_start;
    odd_end->next = NULL;
    head = even_start;
}
// template <class T>
void anythinng(node *head)
{
    node *temp = head;
    int lenght = 0;

    while (temp != NULL)
    {
        temp = temp->next;
        lenght++;
    }
    cout << lenght << endl;
    int arr[lenght];
    temp = head;
    for (int i = 0; i < lenght; i++)
    {
        arr[i] = temp->data;
        temp = temp->next;
    }
    for (int j = 0; j < lenght / 2; j++)
    {
        if (arr[j] != arr[lenght - j - 1])
        {
            cout << "Not Palindrome";
            break;
        }
        else
        {
            cout << "Palindrome";
            break;
        }
    }
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
bool search(node *head, int key)
{
    node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

int main()
{
    node *head = NULL;
    // insert_at_tail(head,17);
    // insert_at_tail(head,15);
    insert_at_tail(head, 1);
    insert_at_tail(head, 0);
    insert_at_tail(head, 2);
    // insert_at_tail(head,5);
    insert_at_tail(head, 0);
    // insert_at_tail(head,1);
    // insert_at_tail(head,7);
    insert_at_tail(head, 1);
    insert_at_tail(head,3);
    // insert_at_tail(head, 2);
    // display(head);

    anythinng(head);

    // insert_node_after(head,5,2);
    // display(head);

    // delete_last_node(head);
    // display(head);

    // delete_any_node(head,2);
    // display(head);

    // update_node(head,3,6);
    // display(head);

    // all_even_first_all_odd_end(head);
    // display(head);
    return 0;
}
