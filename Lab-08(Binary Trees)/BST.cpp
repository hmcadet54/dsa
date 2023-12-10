#include <iostream>
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

node *insertBST(node *&root, int val)
{
    if (root == NULL)
    {
        return new node(val);
    }
    if (val < root->data)
    {
        root->left = insertBST(root->left, val);
    }
    else
    {
        root->right = insertBST(root->right, val);
    }
    return root;
}
int height(node *root)
{
    int x, y;
    if (root == NULL)
    {
        return 0;
    }
    x = height(root->left);
    y = height(root->right);
    return (x > y) ? x + 1 : y + 1;
}

node *Inpre(node *root)
{
    while (root && root->right != NULL)
    {
        root = root->right;
    }
    return root;
}
node *InSuc(node *root)
{
    while (root && root->left != NULL)
    {
        root = root->left;
    }
    return root;
}


node *deletebst(node *root, int key)
{
    if (root == NULL)
    {
        return root; // Key not found, return the original root
    }

    if (key < root->data)
    {
        root->left = deletebst(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = deletebst(root->right, key);
    }
    else
    {
        // Node with key found, handle deletion
        if (root->left == NULL)
        {
            node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            node *temp = root->left;
            free(root);
            return temp;
        }
        // inoreder predeccessor
        // node *temp=Inpre(root->left);
        // root->data=temp->data;
        // root->left=deletebst(root->left, temp->data);


        // inorder successor
        node *temp = InSuc(root->right); 
        root->data = temp->data;
        root->right = deletebst(root->right, temp->data);
    }
    return root;
}
int countNodes(node *&root)
{
    if (root == NULL)
    {
        return 0;
    }
    int count = (1 + countNodes(root->left) + countNodes(root->right));
    return count;
}
bool isComp(node *root, int ind, int n_nodes)
{
    if (root == NULL)
    {
        return true;
    }
    if (ind >= n_nodes)
    {
        return false;
    }

    return (isComp(root->left, 2 * ind + 1, n_nodes) && isComp(root->right, 2 * ind + 2, n_nodes));
}
bool IsFullBST(node *root)
{
    if(root==NULL)
    {
        return true;
    }
    if((root->left==NULL || root->right==NULL)&& (root->left!=NULL || root->right!=NULL))
    {
        return IsFullBST(root->left)&&IsFullBST(root->right);
    }
    return false;
}
int countBSTNodes(node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    if (IsFullBST(root))
    {
        return 1 + countBSTNodes(root->left) + countBSTNodes(root->right);
    }

    return countBSTNodes(root->left) + countBSTNodes(root->right);
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
    node *root = NULL;
    int array[6] = {5, 1, 3, 4, 2, 7};
    for (int i = 0; i < 6; i++)
    {
        root = insertBST(root, array[i]);
    }

    inorder(root);
    cout<<endl;
    deletebst(root,3);
    preorder(root);
    cout<<endl;
    cout<<height(root);

    
    if(isComp(root,0,countNodes(root)))
    {
        cout<<"Binary Tree is Complete";
    }
    else
    {
        cout<<"Binary Tree is not complete";
    }

    cout<<countBSTNodes(root);
    
    
}