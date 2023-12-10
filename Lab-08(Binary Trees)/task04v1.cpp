#include <iostream>
#include <vector>
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
vector<int> searchNode(node *&root, int key1, int key2, int key3)
{
    vector<int> result;
    if (root == NULL)
    {
        return result;
    }
    int closest = root->data;
    if (abs(root->data - key1) < abs(closest - key1))
    {
        closest = root->data;
    }
    if (abs(root->data - key2) < abs(closest - key2))
    {
        closest = root->data;
    }
    if (abs(root->data - key3) < abs(closest - key3))
    {
        closest = root->data;
    }
    if (closest == key1 || closest == key2 || closest == key3)
    {
        result.push_back(closest);
    }
    vector<int> leftNodes = searchNode(root->left, key1, key2, key3);
    result.insert(result.end(), leftNodes.begin(), leftNodes.end());
    vector<int> rightNodes = searchNode(root->right, key1, key2, key3);
    result.insert(result.end(), rightNodes.begin(), rightNodes.end());
    return result;
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

    cout << "Key: " << key << endl;

    vector<int> closestNodes = searchNode(root, key - 1, key, key + 1);
    cout << "Key: " << key << endl;
    cout << "Closest Values: ";
    for (int i = 0; i < closestNodes.size(); i++)
    {
        cout << closestNodes[i] << " ";
    }
}