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

void Inserttail_L(node *&L, int value)
{
    node *n = new node(value);
    if (L== NULL)
    {
        L = n;
        return;
    }
    node *temp = L;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->prev = temp;
}
void Inserttail_M(node *&M, int value)
{
    node *n = new node(value);
    if (M== NULL)
    {
        M = n;
        return;
    }
    node *temp = M;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->prev = temp;
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
    node *L = NULL;
    node *M=NULL;
    Inserttail_L(L, 1);
    Inserttail_L(L, 2);
    Inserttail_L(L, 3);
    Inserttail_L(L, 4);
    Inserttail_L(L, 5);
    cout<<"L-Nodes"<<endl;
    Display(L);

    cout<<endl;
    Inserttail_M(M, 6);
    Inserttail_M(M, 7);
    Inserttail_M(M, 8);
    Inserttail_M(M, 9);
    Inserttail_M(M, 10);
    cout<<"MNodes"<<endl;
    Display(M);
    cout<<endl;


    cout<<"Concatinated Nodes"<<endl;
    ConcatinateL_M_Nodes(L,M);
    Display(L);
    cout<<endl;
 
    return 0;
}