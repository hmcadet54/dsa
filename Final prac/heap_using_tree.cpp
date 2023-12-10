#include <iostream>
using namespace std;

template <class T1, class T2>
class Node
{
public:
    pair<T1, T2> data;
    Node<T1, T2> *left;
    Node<T1, T2> *right;

    Node(pair<T1, T2> val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

template <class T1, class T2>
class Heap
{
public:
    Node<T1, T2> *root;

    Heap()
    {
        root = nullptr;
    }

    void insert(pair<T1, T2> val)
    {
        Node<T1, T2> *newNode = new Node<T1, T2>(val);

        if (root == nullptr)
        {
            root = newNode;
            return;
        }

        Node<T1, T2> *temp = root;
        while (temp->left != nullptr && temp->right != nullptr)
        {
            if (temp->left->data > temp->right->data)
            {
                temp = temp->right;
            }
            else
            {
                temp = temp->left;
            }
        }

        if (temp->left == nullptr)
        {
            temp->left = newNode;
        }
        else
        {
            temp->right = newNode;
        }
    }

    void print(Node<T1, T2> *node)
    {
        if (node == nullptr)
        {
            return;
        }

        print(node->left);
        cout << "(" << node->data.first << ", " << node->data.second << ") ";
        print(node->right);
    }

    void print()
    {
        print(root);
    }
};

int main()
{
    Heap<int, string> heap;
    heap.insert(make_pair(1, "abdullah"));
    heap.insert(make_pair(2, "haroon"));
    heap.insert(make_pair(3, "shafiq"));
    heap.insert(make_pair(4, "zaffar"));
    heap.insert(make_pair(5, "malik"));
    heap.insert(make_pair(6, "taha"));

    heap.print();
    cout << endl;
}
