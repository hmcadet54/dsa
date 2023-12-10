#include <iostream>
#include<queue>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};
node* InsertNode(node *&root, int data)
{
    if (root == NULL) {
        
        return new node(data);
    }
 
    queue<node*> q;
    q.push(root);
 
    while (!q.empty()) {
        node* temp = q.front();
        q.pop();
 
        if (temp->left != NULL)
            q.push(temp->left);
        else {
            temp->left = new node(data);
            return root;
        }
 
        if (temp->right != NULL)
            q.push(temp->right);
        else {
            temp->right = new node(data);
            return root;
        }
    }
}

void preorder(node *&root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(node *&root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void postorder(node *&root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);

    cout<<"Before Inserting !"<<endl;
    cout<<"Preorder: ";
    preorder(root);
    cout<<endl<<"Inorder: ";
    inorder(root);
    cout<<endl<<"Postrder: ";
    postorder(root);

    root=InsertNode(root,6);
    root=InsertNode(root,7);
    root=InsertNode(root,8);
    
    cout<<endl;
    cout<<"After Inserting !"<<endl;
    cout<<"Preorder: ";
    preorder(root);
    cout<<endl<<"Inorder: ";
    inorder(root);
    cout<<endl<<"Postrder: ";
    postorder(root);



}