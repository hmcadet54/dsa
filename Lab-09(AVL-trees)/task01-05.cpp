#include <iostream>
#include <windows.h>
#include <vector>
using namespace std;


class node
{
public:
    int data;
    int height;
    node *left;
    node *right;
    node(int val) : data(val), left(NULL), right(NULL), height(1) {}
};
int maxhieght(int a, int b)
{
    return (a > b) ? a : b;
}
// utility function for getting height of tree
int hieght(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return root->height;
}
// for
int balanceFactor(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return hieght(root->left) - hieght(root->right);
}
void updateHeight(node *root)
{
    if (root != NULL)
    {
        root->height = 1 + maxhieght(hieght(root->left), hieght(root->right));
    }
}
node *rotateLeft(node *x)
{
    node *y = x->right;
    node *temp = y->left;

    y->left = x;
    x->right = temp;
    updateHeight(x);
    updateHeight(y);
    return y;
}
node *rotateRight(node *y)
{
    node *x = y->left;
    node *temp = x->right;
    x->right = y;
    y->left = temp;
    updateHeight(y);
    updateHeight(x);

    return x;
}

node *insert(node *root, int data)
{
    if (root == NULL)
    {
        return new node(data);
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

node *deleteNode(node *root, int data)
{
    if (root == NULL)
    {
        return root;
    }

    if (data < root->data)
    {
        root->left = deleteNode(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = deleteNode(root->right, data);
    }
    else
    {
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
        node *temp=Inpre(root->left);
        root->data=temp->data;
        root->left=deleteNode(root->left, temp->data);


        // inorder successor
        // node *temp = InSuc(root->right); 
        // root->data = temp->data;
        // root->right = deleteNode(root->right, temp->data);

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

int searchNode(node *&root, int key)
{
    if (root == NULL)
    {
        return -1;
    }
    if (root->data == key)
    {
        return root->data;
    }
    int leftNode = searchNode(root->left, key);
    if (leftNode != -1)
    {
        return leftNode;
    }
    int rightNode = searchNode(root->right, key);
    if (rightNode != -1)
    {
        return rightNode;
    }
    else
    {
        return -1;
    }
}
void preorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
int inorder(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    inorder(root->left);
    return root->data;
    inorder(root->right);
}
void postorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}
void inorderforvector(node *root, vector<int>&elem)
{
    if (root == NULL)
    {
        return;
    }
    inorderforvector(root->left,elem);
    elem.push_back(root->data);
    inorderforvector(root->right,elem);
}

void SL(node *root)
{
    vector<int> fromInOrd;
    inorderforvector(root,fromInOrd);
    int len=fromInOrd.size();
    cout<<"Smallest: "<<fromInOrd[0]<<endl;
    cout<<"largest: "<<fromInOrd[len-1]<<endl;

}

int main()
{
    // Task-01
    cout << "Task-01" << endl;
    node *root = NULL;
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 3);
    root = insert(root, 4);
    root = insert(root, 5);
    cout << "Pre-Order: ";
    preorder(root);
    cout << endl;
    cout << endl;

    // Task-02
    cout << "Task-02" << endl;
    deleteNode(root, 4);
    cout << "Pre-Order After Deletion'3': ";
    preorder(root);
    cout << endl;
    cout << endl;

    // Task-03
    cout << "Task-03" << endl;
    cout << "In-Order: ";
    cout<<inorder(root);
    cout << endl;
    cout << "Post-Order: ";
    postorder(root);
    cout << endl;
    cout << endl;

    // Task-04
    cout << "Task-04" << endl;
    int key;
    cout << "Enter Key you want to seacrh: ";
    cin >> key;

    if (searchNode(root, key)!=-1)
    {
        cout<<"Found: "<<searchNode(root,key);
    }
    else
    {
        root = insert(root, key);
        cout<<"Value not found, now inserted in tree"<<endl;
        cout<<"Pre-Order after Inserting '"<<key<<"' :";
        preorder(root);
        cout<<endl;
        cout<<"Again Searching..."<<endl;
        Sleep(3000);
        cout<<"Found : "<<searchNode(root,key);
    }
    cout << endl;
    cout << endl;
    cout << "Task-05" << endl;
    SL(root);


}