#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;
    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
    Node* head;
    Node* tail;
public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void displayForward() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << (temp->next ? " <-> " : "");
            temp = temp->next;
        }
        cout << endl;
    }

    void displayBackward() {
        Node* temp = tail;
        while (temp) {
            cout << temp->data << (temp->prev ? " <-> " : "");
            temp = temp->prev;
        }
        cout << endl;
    }
};
