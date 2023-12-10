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
int countNodes(node *&root)
{
    if(root==NULL)
    {
        return 0;
    }
    int count=(1+countNodes(root->left)+countNodes(root->right));
    return count;  
}
bool isComp(node *root, int ind, int n_nodes)
{
    if(root==NULL)
    {
        return true;
    }
    if(ind>=n_nodes)
    {
        return false;
    }

    return (isComp(root->left,2*ind+1,n_nodes)&&isComp(root->right,2*ind+2,n_nodes));
}
bool isFullBST(node* root) {
    int n_nodes = countNodes(root);
    return isComp(root, 0, n_nodes);
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

    root=InsertNode(root,6);
    root=InsertNode(root,7);
    // root=InsertNode(root,8);
    
    cout<<endl;
    cout<<"After Inserting !"<<endl;
    cout<<"Preorder: ";
    preorder(root);
    cout<<endl;
    cout<<endl;

    if(isFullBST(root))
    {
        cout<<"Binary Tree is Complete";
    }
    else
    {
        cout<<"Binary Tree is not complete";
    }
    



}