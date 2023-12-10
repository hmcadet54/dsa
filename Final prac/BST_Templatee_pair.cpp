#include <iostream>
using namespace std;

template <class T1, class T2>
class node
{
public:
    pair<T1, T2> data;
    node<T1, T2> *left;
    node<T1, T2> *right;

    node(pair<T1, T2> value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};
template <class T1, class T2>
node<T1, T2> *insertBST(node<T1, T2> *&root, pair<T1, T2> val)
{
    if (root == NULL)
    {
        return new node<T1, T2>(val);
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
template <class T1, class T2>
int height(node<T1, T2> *root)
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
template <class T1, class T2>
node<T1, T2> *Inpre(node<T1, T2> *root)
{
    while (root && root->right != NULL)
    {
        root = root->right;
    }
    return root;
}
template <class T1, class T2>
node<T1, T2> *InSuc(node<T1, T2> *root)
{
    while (root && root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

template <class T1, class T2>
node<T1, T2> *deletebst(node<T1, T2> *root, pair<T1, T2> key)
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
        // node<T1,T2>with key found, handle deletion
        if (root->left == NULL)
        {
            node<T1, T2> *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            node<T1, T2> *temp = root->left;
            free(root);
            return temp;
        }
        // inoreder predeccessor
        // node<T1,T2>*temp=Inpre(root->left);
        // root->data=temp->data;
        // root->left=deletebst(root->left, temp->data);

        // inorder successor
        node<T1, T2> *temp = InSuc(root->right);
        root->data = temp->data;
        root->right = deletebst(root->right, temp->data);
    }
    return root;
}
template <class T1, class T2>
int countNodes(node<T1, T2> *&root)
{
    if (root == NULL)
    {
        return 0;
    }
    int count = (1 + countNodes(root->left) + countNodes(root->right));
    return count;
}
template <class T1, class T2>
bool isComp(node<T1, T2> *root, int ind, int n_nodes)
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
template <class T1, class T2>
bool IsFullBST(node<T1, T2> *root)
{
    if (root == NULL)
    {
        return true;
    }
    if ((root->left == NULL && root->right != NULL) || (root->left != NULL && root->right == NULL))
    {
        return false;
    }

    return IsFullBST(root->left) && IsFullBST(root->right);
}
template <class T1, class T2>
int countBSTNodes(node<T1, T2> *root)
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
template <class T1, class T2>
void preorder(node<T1, T2> *&root)
{
    if (root == NULL)
    {
        return;
    }
    cout << "(" << root->data.first << ", ";
    cout << root->data.second << ")"
         << " ";
    preorder(root->left);
    preorder(root->right);
}
template <class T1, class T2>
void inorder(node<T1, T2> *&root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << "(" << root->data.first << ", ";
    cout << root->data.second << ")"
         << " ";
    inorder(root->right);
}
template <class T1, class T2>
void postorder(node<T1, T2> *&root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << "(" << root->data.first << ", ";
    cout << root->data.second << ")"
         << " ";
}

int main()
{
    node<int, string> *root = NULL;
    pair<int, string> array[6] = {make_pair(1, "abdullah"), make_pair(0, "haroon"), make_pair(6, "shafiq"), make_pair(9, "zaffar"), make_pair(3, "malik"), make_pair(4, "taha")};
    for (int i = 0; i < 6; i++)
    {
        root = insertBST(root, array[i]);
    }
    inorder(root);
    deletebst(root, array[0]);
    cout << endl;
    inorder(root);
    cout << endl;
    preorder(root);
    cout << endl;
    postorder(root);
    cout << endl;

    int nodes_cout = countBSTNodes(root);
    cout << "nodes: " << nodes_cout << endl;

    bool full = IsFullBST(root);
    cout << "answer: " << full << endl;
    cout<<"Do you want to insert a new pair?(int, string): ";
    int x;
    cin>>x;
    string y;
    cin>>y;
    insertBST(root,make_pair(x,y));
    inorder(root);
 

}