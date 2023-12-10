#include <iostream>
using namespace std;

template <class T>
class node
{
public:
    T data;
    node<T> *next;

    node(T value)
    {
        data = value;
        next = NULL;
    }
};

// task 01(a)
template <class T>
void insert_at_tail(node<T> *&head, T value)
{
    node<T> *n = new node<T>(value);
    if (head == NULL)
    {
        head = n;
        return;
    }
    node<T> *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}


template <class T>
void PalindromeChecker(node<T> *head)
{
    node<T> *temp = head;
    int lenght = 0;

    while (temp != NULL)
    {
        temp = temp->next;
        lenght++;
    }

    T arr[lenght];
    temp = head;
    for (int i = 0; i < lenght; i++)
    {
        arr[i] = temp->data;
        temp = temp->next;
    }
    bool palindrome=true;
    for (int j = 0; j < lenght / 2; j++)
    {
        if (arr[j] != arr[lenght - j - 1])
        {
            palindrome=false;
            break;
        }
    }
    if(palindrome){
        cout<<"Palindrome"<<endl;
    }
    else{
        cout<<"Not Palindrome"<<endl;
    }
}

template <class T>
void display(node<T> *head)
{
    node<T> *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    node<string> *head = NULL;
    insert_at_tail<string>(head, "B");
    insert_at_tail<string>(head, "O");
    insert_at_tail<string>(head, "R");
    insert_at_tail<string>(head, "R");
    insert_at_tail<string>(head, "O");
    insert_at_tail<string>(head, "W");
    insert_at_tail<string>(head, "O");
    insert_at_tail<string>(head, "R");
    insert_at_tail<string>(head, "R");
    insert_at_tail<string>(head, "O");
    insert_at_tail<string>(head, "B");
    display(head);
    PalindromeChecker(head);
    cout << endl;
    node<int> *head1 = NULL;
    insert_at_tail<int>(head1, 1);
    insert_at_tail<int>(head1, 0);
    insert_at_tail<int>(head1, 2);
    insert_at_tail<int>(head1, 0);
    insert_at_tail<int>(head1, 1);
    display(head1);
    PalindromeChecker(head1);

    cout << endl;
    node<int> *head2 = NULL;
    insert_at_tail<int>(head2, 1);
    insert_at_tail<int>(head2, 0);
    insert_at_tail<int>(head2, 2);
    // insert_at_tail<int>(head2, 4);
    insert_at_tail<int>(head2, 1);
    display(head2);
    PalindromeChecker(head2);


    return 0;
}
