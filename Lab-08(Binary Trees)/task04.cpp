#include <iostream>
#include <stack>
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
int searchNode(node *&root, int key1, int key2, int key3)
{
    if (root == NULL)
    {
        return -1;
    }
    if (root->data == key1 || root->data == key2 || root->data == key1)
    {
        return root->data;
    }
    int leftNode = searchNode(root->left, key1, key2, key3);
    if (leftNode != -1)
    {
        return leftNode;
    }
    int rightNode = searchNode(root->right, key1, key2, key3);
    if (rightNode != -1)
    {
        return rightNode;
    }
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
int ceil(int x)
{
    return x + 1;
}
int floor(int x)
{
    if (x == 0)
    {
        return 0;
    }
    return x - 1;
}

int main()
{
    node *root = NULL;
    int array[6] = {10, 5, 11, 4, 7, 8};
    for (int i = 0; i < 6; i++)
    {
        root = insertBST(root, array[i]);
    }
    int key;
    cout << "Enter the value you want find the closest level: ";
    cin >> key;

    cout << endl
         << "Ceil or Floor (c/f): ";
    char key1;
    cin >> key1;
    if (key1 == 'c')
    {
        key = ceil(key);
    }
    else if (key1 == 'f')
    {
        key = floor(key);
    }
    if (key > 12 || key < 3)
    {
        cout << "Error! Out of Range";
        exit(0);
    }

    cout << "Key: " << key << endl;

    cout << "Closest Value: " << searchNode(root, key - 1, key, key + 1);
}