#include <iostream>
#include <queue>
#include <windows.h>
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
node *InsertNode(node *&root, int data)
{
    if (root == NULL)
    {

        return new node(data);
    }

    queue<node *> q;
    q.push(root);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        if (temp->left != NULL)
            q.push(temp->left);
        else
        {
            temp->left = new node(data);
            return root;
        }

        if (temp->right != NULL)
            q.push(temp->right);
        else
        {
            temp->right = new node(data);
            return root;
        }
    }
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

int searchNode(node *&root, int key, int level)
{
    if (root == NULL)
    {
        return -1;
    }
    if (root->data == key)
    {
        return level+1;
    }
    int leftNode = searchNode(root->left, key, level + 1);
    if (leftNode != -1)
    {
        return leftNode+1;
    }
    int rightNode = searchNode(root->right, key, level + 1);
    if (rightNode != -1)
    {
        return rightNode+1;
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

int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    int key;
    cout << "Enter Key you want to seacrh: ";
    cin >> key;

    if (searchNode(root, key, 0) != -1)
    {
        cout << "Found at adress: " << searchNode(root, key, 0);
    }
    else
    {
        root = InsertNode(root, key);
        cout << "Value not found, now inserted in tree" << endl;
        cout << "Preorder: ";
        preorder(root);
        cout << endl;
        cout << "Again Searching..." << endl;
        Sleep(3000);
        cout << "Found at at adress: " << searchNode(root, key, 0);
    }
}