#include <iostream>
#include <windows.h>
#include <vector>
using namespace std;

template <class T1, class T2>
class node
{
public:
    pair<T1, T2> data;
    int height;
    node<T1, T2> *left;
    node<T1, T2> *right;
    node(pair<T1, T2> val) : data(val), left(NULL), right(NULL), height(1) {}
};
int maxhieght(int a, int b)
{
    return (a > b) ? a : b;
}
// utility function for getting height of tree
template <class T1, class T2>
int hieght(node<T1, T2> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return root->height;
}
// for

template <class T1, class T2>
int balanceFactor(node<T1, T2> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return hieght(root->left) - hieght(root->right);
}

template <class T1, class T2>
void updateHeight(node<T1, T2> *root)
{
    if (root != NULL)
    {
        root->height = 1 + maxhieght(hieght(root->left), hieght(root->right));
    }
}
template <class T1, class T2>
node<T1, T2> *rotateLeft(node<T1, T2> *x)
{
    node<T1, T2> *y = x->right;
    node<T1, T2> *temp = y->left;

    y->left = x;
    x->right = temp;
    updateHeight(x);
    updateHeight(y);
    return y;
}
template <class T1, class T2>
node<T1, T2> *rotateRight(node<T1, T2> *y)
{
    node<T1, T2> *x = y->left;
    node<T1, T2> *temp = x->right;
    x->right = y;
    y->left = temp;
    updateHeight(y);
    updateHeight(x);

    return x;
}

template <class T1, class T2>
node<T1, T2> *insert(node<T1, T2> *root, pair<T1, T2> data)
{
    if (root == NULL)
    {
        return new node<T1, T2>(data);
    }
    if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insert(root->right, data);
    }
    else
    {
        return root;
    }
    updateHeight(root);
    int bal = balanceFactor(root);

    if (bal > 1)
    {
        if (data < root->left->data)
        {
            return rotateRight(root);
        }
        else
        {
            root->left = rotateLeft(root->left);
            return rotateRight(root);
        }
    }
    if (bal < -1)
    {
        if (data > root->right->data)
        {
            return rotateLeft(root);
        }
        else
        {
            root->right = rotateRight(root->right);
            return rotateLeft(root);
        }
    }
    return root;
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
node<T1, T2> *deletenode(node<T1, T2> *root, pair<T1, T2> data)
{
    if (root == NULL)
    {
        return root;
    }

    if (data < root->data)
    {
        root->left = deletenode<T1, T2>(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = deletenode<T1, T2>(root->right, data);
    }
    else
    {
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
        node<T1, T2> *temp = Inpre(root->left);
        root->data = temp->data;
        root->left = deletenode<T1, T2>(root->left, temp->data);

        // inorder successor
        // node<T1,T2> *temp = InSuc(root->right);
        // root->data = temp->data;
        // root->right = deletenode<T1,T2>(root->right, temp->data);
    }

    if (root == NULL)
    {
        return root;
    }

    updateHeight(root);

    int balance = balanceFactor(root);

    if (balance > 1)
    {
        if (balanceFactor(root->left) >= 0)
        {
            return rotateRight(root);
        }
        else
        {
            root->left = rotateLeft(root->left);
            return rotateRight(root);
        }
    }

    if (balance < -1)
    {
        if (balanceFactor(root->right) <= 0)
        {
            return rotateLeft(root);
        }
        else
        {
            root->right = rotateRight(root->right);
            return rotateLeft(root);
        }
    }

    return root;
}

template <class T1, class T2>
pair<T1, T2> searchnode(node<T1, T2> *&root, pair<T1, T2> key)
{
    if (root == NULL)
    {
        return make_pair(T1(), T2());
    }
    if (root->data == key)
    {
        return root->data;
    }
    auto leftnode = searchnode<T1, T2>(root->left, key);
    if (leftnode != make_pair(T1(), T2()))
    {
        return leftnode;
    }
    auto rightnode = searchnode<T1, T2>(root->right, key);
    if (rightnode != make_pair(T1(), T2()))
    {
        return rightnode;
    }
    else
    {
        return make_pair(T1(), T2());
    }
}
template <class T1, class T2>
void preorder(node<T1, T2> *root)
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
void inorder(node<T1, T2> *root)
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
void postorder(node<T1, T2> *root)
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
template <class T1, class T2>
void inorderforvector(node<T1, T2> *root, vector<pair<T1,T2>> &elem)
{
    if (root == NULL)
    {
        return;
    }
    inorderforvector(root->left, elem);
    elem.push_back(root->data);
    inorderforvector(root->right, elem);
}

template <class T1, class T2>
void SL(node<T1, T2> *root)
{
    vector<pair<T1,T2>> fromInOrd;
    inorderforvector(root, fromInOrd);
    int len = fromInOrd.size();
    cout << "Smallest: " << fromInOrd[0] << endl;
    cout << "largest: " << fromInOrd[len - 1] << endl;
}

int main()
{
    // Task-01
    cout << "Task-01" << endl;
    node<int, string> *root = NULL;
    root = insert<int ,string>(root, make_pair(1,"abdullah"));
    root = insert<int ,string>(root, make_pair(7,"haroon"));
    root = insert<int ,string>(root, make_pair(0,"ch123"));
    root = insert<int ,string>(root, make_pair(6,"BCS-2d"));
    root = insert<int ,string>(root, make_pair(19,"ali"));

    cout << "Pre-Order: ";
    preorder(root);
    cout << endl;
    cout << endl;
    inorder(root);

    // Task-02
    cout << "Task-02" << endl;
    deletenode<int, string>(root, make_pair(7,"haroon"));
    cout << "Pre-Order After Deletion(7,haroon) : ";
    preorder(root);
    cout << endl;
    cout << endl;

    // // Task-03
    // cout << "Task-03" << endl;
    // cout << "In-Order: ";
    // cout << inorder(root);
    // cout << endl;
    // cout << "Post-Order: ";
    // postorder(root);
    // cout << endl;
    // cout << endl;

    // Task-04
    cout << "Task-04" << endl;
    int key;
    cout << "Enter Key you want to seacrh:(int,string): ";
    cin >> key;
    string y;
    cin>>y;
    pair<int,string>result;

    if (searchnode<int, string>(root, make_pair(key, y)) !=make_pair(int(),string()) )
    {
        result= searchnode<int,string>(root, make_pair(key, y));
        cout<<"Found ("<<result.first<<", "<<result.second<<")"<<endl;
    }
    else
    {
        root = insert<int, string>(root, make_pair(key, y));
        cout << "Value not found, now inserted in tree" << endl;
        cout << "Pre-Order after Inserting '" << key << "' :";
        preorder(root);
        cout << endl;
        cout << "Again Searching..." << endl;
        Sleep(3000);
         result= searchnode<int,string>(root, make_pair(key, y));
        cout<<"Found ("<<result.first<<", "<<result.second<<")"<<endl;
    }
    cout << endl;
    cout << endl;
    // cout << "Task-05" << endl;
    // SL(root);
}