
//What I did:
// 1-created BST-1 with elements 5,6,3,2,4 using function insertBST().
// 2-created BST-2 with elements 2,3,1,7,6 using function insertBST().
// 3- Stored elements of both BST in vector named bst1 and bst1.
// 4- merged these two vector in megedbst using predefine merge() function
// 5- using mergeBST created new tree called MEGEDBST which shows inorder as "1 2 2 3 3 4 5 6 6 7".

#include <iostream>
#include <vector>
#include <algorithm>
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

void inorderforinserting(node *&root, vector<int> &in)
{
    if (root == NULL)
    {
        return;
    }
    inorderforinserting(root->left, in);
    in.push_back(root->data);
    inorderforinserting(root->right, in);
}
void inorder(node *&root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main()
{
    node *root = NULL;
    vector<int> bst1, bst2;
    int array1[5] = {5, 6, 3, 2, 4};
    for (int i = 0; i < 5; i++)
    {
        root = insertBST(root, array1[i]);
    }
    inorderforinserting(root, bst1);
    node *root1 = NULL;
    int array2[5] = {2,3,1,7,6};
    for (int i = 0; i < 5; i++)
    {
        root1 = insertBST(root1, array2[i]);
    }
    inorderforinserting(root1, bst2);
    vector <int> mergebst(bst1.size()+bst2.size());
    merge(bst1.begin(),bst1.end(),bst2.begin(),bst2.end(),mergebst.begin());


    node *mergedBST =NULL;
    for (int i=0;i<mergebst.size();i++)
    {
        mergedBST=insertBST(mergedBST,mergebst[i]);
    }
    inorder(mergedBST);
    

}