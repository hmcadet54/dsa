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
void insertHead(node *&head, int value)
{
    node *n = new node(value);
    n->next = head;
    head->prev = n;
    head = n;
}

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
void reverse(node *&head)
{
    node *ptr1 =head;
    node *ptr2 =ptr1->next;
    ptr1->next=NULL;
    ptr1->prev=ptr2;

    while(ptr2!=NULL)
    {
        ptr2->prev=ptr2->next;
        ptr2->next=ptr1;
        ptr1=ptr2;
        ptr2=ptr2->prev;
    }
    head=ptr1;
}
void ConcatinateL_M_Nodes(node *L, node *M)
{
    node* L_node=L;
    node* M_node=M;

    while(L_node->next!=NULL)
    {
        L_node=L_node->next;
    }
    L_node->next=M;
    M_node->prev=L;

}

void Task(node *&head)
{
    node *temp = head;
    node *NewList= NULL;
    node *ExtractedList = NULL;

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
    node *head = NULL;
    Inserttail(head, 10);
    Inserttail(head, 4);
    Inserttail(head, 9);
    Inserttail(head, 1);
    Inserttail(head, 3);
    Inserttail(head, 5);
    Inserttail(head, 9);
    Inserttail(head, 4);
    Display(head);
    Task(head);
    return 0;
}