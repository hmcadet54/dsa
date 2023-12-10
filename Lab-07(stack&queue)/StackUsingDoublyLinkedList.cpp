#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next;
    node* prev;

    node(int value) {
        data = value;
        next = prev = NULL;
    }
};

class stack {
    node* top;

public:
    stack() {
        top = NULL;
    }

    void push(int x) {
        node* n = new node(x);
        if (top) {
            n->next = top;
            top->prev = n;
        }
        top = n;
    }

    void pop() {
        if (top != NULL) {
            node* temp = top;
            top = top->next;
            if (top) {
                top->prev = NULL;
            }
            delete temp;
        }
    }

    bool empty() {
        return top == NULL;
    }

    void display() {
        if (top != NULL) {
            node* temp = top;
            while (temp != NULL) {
                cout << temp->data << "->";
                temp = temp->next;
            }
            cout << "NULL" << endl;
        }
    }
};

int main() {
    stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.display();

    return 0;
}
