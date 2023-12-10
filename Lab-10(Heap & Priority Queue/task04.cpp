#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>

using namespace std;

struct Node
{
    char data;
    int freqq;
    Node *left;
    Node *right;

    Node(char data, int freqq)
    {
        this->data = data;
        this->freqq = freqq;
        left = right = NULL;
    }
};

struct Compare
{
    bool operator()(Node *left, Node *right)
    {
        return left->freqq > right->freqq;
    }
};

void AsCode(Node *node, string code, unordered_map<char, string> &huffmanCodes)
{
    if (node == nullptr)
    {
        return;
    }

    if (node->left == nullptr && node->right == nullptr)
    {
        huffmanCodes[node->data] = code;
    }

    AsCode(node->left, code + "0", huffmanCodes);
    AsCode(node->right, code + "1", huffmanCodes);
}

Node* buildHuffmanTree(string text)
{
    unordered_map<char, int> freqMap;
    for (char c : text)
    {
        freqMap[c]++;
    }

    priority_queue<Node *, vector<Node *>, Compare> pq;
    for (auto pair : freqMap)
    {
        pq.push(new Node(pair.first, pair.second));
    }

    while (pq.size() > 1)
    {
        Node *left = pq.top();
        pq.pop();
        Node *right = pq.top();
        pq.pop();

        Node *temp = new Node('$', left->freqq + right->freqq);
        temp->left = left;
        temp->right = right;

        pq.push(temp);
    }

    return pq.top(); 
}



int main()
{
    string text = "BCS-3D";
    Node* root = buildHuffmanTree(text);
    unordered_map<char, string> huffmanCodes;
    AsCode(root, "", huffmanCodes);

    string encodedString = "";
    for (char c : text)
    {
        encodedString += huffmanCodes[c];
    }

    cout << "Encoded string: " << encodedString << endl;

    return 0;
}
