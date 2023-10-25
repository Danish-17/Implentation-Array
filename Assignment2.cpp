#include <iostream>
#include <string>
#include "Header1.h"


using namespace std;



class Stack {
private:
    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    ~Stack() {
        Node* temp;
        while (top != nullptr) {
            temp = top;
            top = top->next;
            delete temp;
        }
    }

    void push(char c) {
        Node* newNode = new Node;
        newNode->data = c;
        newNode->next = top;
        top = newNode;
    }

    char pop() {
        if (top == nullptr) {
            cout << "Stack underflow" << endl;
            return '\0';
        }
        char c = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return c;
    }

    bool isEmpty() {
        return (top == nullptr);
    }
};

void reverseString(string& str) {
    int n = str.length();
    Stack stack;


    for (int i = 0; i < n; i++) {
        stack.push(str[i]);
    }


    for (int i = 0; i < n; i++) {
        str[i] = stack.pop();
    }
}

int main() {
    string str = "Hey Man! How are you?";
    cout << "Original String: " << str << endl;
    reverseString(str);
    cout << "Reversed String: " << str << endl;

    return 0;
}
