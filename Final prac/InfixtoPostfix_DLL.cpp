#include <iostream>
#include <list>

using namespace std;

class Node {
public:
    char data;
    Node* prev;
    Node* next;

    Node(char value) : data(value), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
public:
    Node* head;
    Node* tail;

    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void push_back(char value) {
        Node* newNode = new Node(value);
        if (tail == nullptr) {
            head = tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    char pop_back() {
        if (tail == nullptr) {
            cerr << "Error: Attempting to pop from an empty list." << endl;
            return '\0'; // Return a null character in case of an error
        }

        char value = tail->data;
        Node* prevNode = tail->prev;
        delete tail;
        tail = prevNode;

        if (tail != nullptr) {
            tail->next = nullptr;
        } else {
            head = nullptr; // Set head to null when the last element is popped
        }

        return value;
    }

    char back() {
        if (tail == nullptr) {
            cerr << "Error: Attempting to access back of an empty list." << endl;
            return '\0'; // Return a null character in case of an error
        }

        return tail->data;
    }

    bool empty() {
        return head == nullptr;
    }
};

int prec(char c) {
    if (c == '^') {
        return 3;
    } else if (c == '*' || c == '/') {
        return 2;
    } else if (c == '+' || c == '-') {
        return 1;
    } else {
        return -1;
    }
}

string infixTOpostfix(string infix) {
    DoublyLinkedList list;
    string postfix = "";

    for (int i = 0; i < infix.length(); i++) {
        if ((infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= 'A' && infix[i] <= 'Z')) {
            postfix += infix[i];
        } else if (infix[i] == '(') {
            list.push_back(infix[i]);
        } else if (infix[i] == ')') {
            while (!list.empty() && list.back() != '(') {
                postfix += list.pop_back();
            }
            if (!list.empty() && list.back() == '(') {
                list.pop_back();
            } else {
                cerr << "Error: Mismatched parentheses." << endl;
                return "";
            }
        } else {
            while (!list.empty() && prec(list.back()) >= prec(infix[i])) {
                postfix += list.pop_back();
            }
            list.push_back(infix[i]);
        }
    }

    while (!list.empty()) {
        if (list.back() == '(') {
            cerr << "Error: Mismatched parentheses." << endl;
            return "";
        }
        postfix += list.pop_back();
    }

    return postfix;
}

int main() {
    cout << infixTOpostfix("((a+b)*c)-d") << endl;
    return 0;
}
