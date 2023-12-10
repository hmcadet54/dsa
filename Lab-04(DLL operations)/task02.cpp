#include <iostream>
#include <utility>
using namespace std;

template <class T>
class node
{
public:
    T data;
    node<T> *next;
    node<T> *prev;

    node(T value)
    {
        data = value;
        next = NULL;
        prev = NULL;
    }
};

template <class T>
void Inserttail(node<T> *&head, T value)
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
    n->prev = temp;
}

template <class T>
void insertHead(node<T> *&head, T value)
{
    node<T> *n = new node<T>(value);
    n->next = head;
    if (head != NULL)
    {
        head->prev = n;
    }
    head = n;
}

template <class T>
void InsertAtPos(node<T> *&head, T value, T pos)
{
    node<T> *n = new node<T>(value);
    node<T> *temp = head;
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

template <class T>
void DeleteAnyNode(node<T> *&head, int pos)
{
    node<T> *temp = head;
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

template <class T>
void Display(node<T> *head)
{
    node<T> *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "<->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

template <class T>
node<T> *reverse(node<T> *&temp)
{
    node<T> *rev = NULL;
    while (temp != NULL)
    {
        insertHead(rev, temp->data);
        temp = temp->next;
    }
    temp = NULL;
    temp = rev;
    return temp;
}
template <class T>
void swapNodes(node<T> *&head, T key1, T key2)
{
    node<T> *temp = head;
    int count = 1;
    node<T> *temp1;
    node<T> *temp2;
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
    node<T> *temp3 = temp1->prev;
    temp1->prev = temp2->prev;
    temp2->prev = temp3;
    temp3 = temp1->next;
    temp1->next = temp2->next;
    temp2->next = temp3;
}
template <class T>
void ConcatinateL_M_Nodes(node<T> *L, node<T> *M)
{
    node<T>* L_node=L;
    node<T>* M_node=M;

    while(L_node->next!=NULL)
    {
        L_node=L_node->next;
    }
    L_node->next=M;
    M_node->prev=L;

}
template <class T>
void Task(node<T> *&head)
{
    node<T> *temp = head;
    node<T> *NewList= NULL;
    node<T> *ExtractedList = NULL;

    int count = 1;

    while (temp != NULL)
    {

        if (count % 2 == 0)
        {
            Inserttail(ExtractedList, temp->data);
        }
        else{
            Inserttail(NewList, temp->data);
        }
        temp = temp->next;
        count++;
    }
    cout<<endl;

    cout<<"Entracted Alternate Elements:"<<endl;
    Display(ExtractedList);
    cout<<endl;

    cout<<"Remaining Elements in Original List:"<<endl;
    Display(NewList);
    cout<<endl;

    cout<<"The Extracted List is now reversed:"<<endl;
    reverse(ExtractedList);
    Display(ExtractedList);
    cout<<endl;

    cout<<"Appended the Original List with Extracted List:"<<endl;
    ConcatinateL_M_Nodes(NewList,ExtractedList);
    Display(NewList);
    cout<<endl;

}

int main()
{
    node<int> *head = NULL;
    Inserttail(head, 1);
    Inserttail(head, 2);
    Inserttail(head, 3);
    Inserttail(head, 4);
    Inserttail(head, 5);
    Display(head);

    node<char> *head1 = NULL;
    Inserttail(head1, 'a');
    Inserttail(head1, 'b');
    Inserttail(head1, 'd');
    Inserttail(head1, 'e');
    Inserttail(head1, 'f');
    Display(head1);

    node <string> *head2=NULL;
    Inserttail<string>(head2,"BCS-3d");
    Inserttail<string>(head2,"BCS-3e");
    Inserttail<string>(head2,"BCS-3f");
    Inserttail<string>(head2,"BCS-3g");
    Inserttail<string>(head2,"BCS-3h");
    Display(head2);


}