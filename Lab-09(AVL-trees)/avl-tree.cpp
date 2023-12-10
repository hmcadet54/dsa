#include <iostream>
using namespace std;

class AVLNode
{
public:
    int data;
    int height;
    AVLNode *left;
    AVLNode *right;

    AVLNode(int k) : data(k), height(1), left(NULL), right(NULL) {}
};

class AVLTree
{
public:
    AVLNode *root;
    AVLTree() : root(NULL) {}
    int max(int a, int b)
    { // Max can be made as per requirement (even in turinary)
        if (a > b)
        {
            return a;
        }
        else if (a == b)
        {
            return a;
        }
        else
        {
            return b;
        }
    }

    int getHeight(AVLNode *node)
    { // Returns the height of the node
        if (node == NULL)
            return 0;
        return node->height;
    }

    int getBalanceFactor(AVLNode *node)
    { // gets the balance factor
        if (node == NULL)
            return 0;
        return getHeight(node->left) - getHeight(node->right); // Left - right
    }

    void updateHeight(AVLNode *node)
    { // Updates the height
        if (node != NULL)
            node->height = 1 + max(getHeight(node->left), getHeight(node->right)); // Updates height after insertion (can be used for deletion as well)
    }

    AVLNode *rotateRight(AVLNode *y)
    {
        AVLNode *x = y->left;
        AVLNode *T2 = x->right;

        x->right = y;
        y->left = T2;

        updateHeight(y);
        updateHeight(x);

        return x;
    }

    AVLNode *rotateLeft(AVLNode *x)
    {
        AVLNode *y = x->right;
        AVLNode *T2 = y->left;

        y->left = x;
        x->right = T2;

        updateHeight(x);
        updateHeight(y);

        return y;
    }

    AVLNode *insert(AVLNode *node, int data)
    {
        if (node == NULL)
            return new AVLNode(data);

        if (data < node->data)
            node->left = insert(node->left, data);
        else if (data > node->data)
            node->right = insert(node->right, data);
        else
            return node; // Duplicate datas not allowed

        updateHeight(node);

        int balance = getBalanceFactor(node); // Gets the balance factor

        // Left Heavy
        if (balance > 1)
        { // Concatenated the LL and LR rotations in one functionality
            if (data < node->left->data)
            {
                return rotateRight(node);
            }
            else
            {
                node->left = rotateLeft(node->left);
                return rotateRight(node);
            }
        }

        // Right Heavy //Concatenated the RR and RL rotations in one functionality
        if (balance < -1)
        {
            if (data > node->right->data)
            {
                return rotateLeft(node);
            }
            else
            {
                node->right = rotateRight(node->right);
                return rotateLeft(node);
            }
        }

        return node;
    }

    int inserttoNode(int d)
    { // Wrapper function because of the recursive nature of inserting elements
        root = insert(root, d);
    }

    int Preorder(AVLNode *top)
    {
        if (top == NULL)
        {
            return 0;
        }
        else
        {
            cout << top->data << " ";
            Preorder(top->left);
            Preorder(top->right);
        }
    }
};

int main()
{
    AVLTree tree;

    tree.inserttoNode(10);
    tree.inserttoNode(20);
    tree.inserttoNode(30);
    tree.inserttoNode(40);
    tree.inserttoNode(50);
    tree.inserttoNode(25);
    tree.inserttoNode(60);

    cout << "Preorder traversal of AVL tree: ";
    tree.Preorder(tree.root);

    return 0;
}