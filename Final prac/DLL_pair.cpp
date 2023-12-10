#include <iostream>
#include <utility>
using namespace std;

template <class T1, class T2>
class node
{
public:
    pair<T1, T2> data;
    node<T1, T2> *next;
    node<T1, T2> *prev;

    node(pair<T1, T2> value)
    {
        data = value;
        next = NULL;
        prev = NULL;
    }
};

template <class T1, class T2>
void Inserttail(node<T1, T2> *&head, pair<T1, T2> value)
{
    node<T1, T2> *n = new node<T1, T2>(value);
    if (head == NULL)
    {
        head = n;
        return;
    }
    node<T1, T2> *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->prev = temp;
}

template <class T1, class T2>
void insertHead(node<T1, T2> *&head, pair<T1, T2> value)
{
    node<T1, T2> *n = new node<T1, T2>(value);
    n->next = head;
    if (head != NULL)
    {
        head->prev = n;
    }
    head = n;
}

template <class T1, class T2>
void InsertAtPos(node<T1, T2> *&head, pair<T1, T2> value, pair<T1, T2> pos)
{
    node<T1, T2> *n = new node<T1, T2>(value);
    node<T1, T2> *temp = head;
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

template <class T1, class T2>
void DeleteAnyNode(node<T1, T2> *&head, int pos)
{
    node<T1, T2> *temp = head;
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

template <class T1, class T2>
void Display(node<T1, T2> *head)
{
    node<T1, T2> *temp = head;
    while (temp != NULL)
    {
        cout << "(" << temp->data.first << ", " << temp->data.second << ") <-> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

template <class T1, class T2>
node<T1, T2> *reverse(node<T1, T2> *&temp)
{
    node<T1, T2> *rev = NULL;
    while (temp != NULL)
    {
        insertHead(rev, temp->data);
        temp = temp->next;
    }
    temp = NULL;
    temp = rev;
    return temp;
}
template <class T1, class T2>
void swapNodes(node<T1, T2> *&head, pair<T1, T2> key1, pair<T1, T2> key2)
{
    node<T1, T2> *temp = head;
    int count = 1;
    node<T1, T2> *temp1;
    node<T1, T2> *temp2;
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
    node<T1, T2> *temp3 = temp1->prev;
    temp1->prev = temp2->prev;
    temp2->prev = temp3;
    temp3 = temp1->next;
    temp1->next = temp2->next;
    temp2->next = temp3;
}
template <class T1, class T2>
void ConcatinateL_M_Nodes(node<T1, T2> *L, node<T1, T2> *M)
{
    node<T1, T2> *L_node = L;
    node<T1, T2> *M_node = M;

    while (L_node->next != NULL)
    {
        L_node = L_node->next;
    }
    L_node->next = M;
    M_node->prev = L;
}
template <class T1, class T2>
void Task(node<T1, T2> *&head)
{
    node<T1, T2> *temp = head;
    node<T1, T2> *NewList = NULL;
    node<T1, T2> *ExtractedList = NULL;

    int count = 1;

    while (temp != NULL)
    {

        if (count % 2 == 0)
        {
            Inserttail(ExtractedList, temp->data);
        }
        else
        {
            Inserttail(NewList, temp->data);
        }
        temp = temp->next;
        count++;
    }
    cout << endl;

    cout << "Entracted Alternate Elements:" << endl;
    Display(ExtractedList);
    cout << endl;

    cout << "Remaining Elements in Original List:" << endl;
    Display(NewList);
    cout << endl;

    cout << "The Extracted List is now reversed:" << endl;
    reverse(ExtractedList);
    Display(ExtractedList);
    cout << endl;

    cout << "Appended the Original List with Extracted List:" << endl;
    ConcatinateL_M_Nodes(NewList, ExtractedList);
    Display(NewList);
    cout << endl;
}

int main()
{
    node<int, int> *head = NULL;

    // Inserting elements using Inserttail function
    Inserttail(head, make_pair(1, 10));
    Inserttail(head, make_pair(2, 20));
    Inserttail(head, make_pair(3, 30));
    Inserttail(head, make_pair(4, 40));
    Inserttail(head, make_pair(5, 50));

    // Displaying the elements
    Display(head);

    node<int,string> *head3=NULL;
    Inserttail<int,string>(head3,make_pair(4489,"abdullah"));
    Inserttail<int,string>(head3,make_pair(4000,"shayan"));
    Inserttail<int,string>(head3,make_pair(4590,"habib"));
    Inserttail<int,string>(head3,make_pair(1234,"hasnain"));
    Inserttail<int,string>(head3,make_pair(6789,"Moiz"));
    Inserttail<int,string>(head3,make_pair(4567,"Usama"));
    Display(head3);

    Task(head3);

    return 0;
}