#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class SinglyLinkedList {
    Node* head;
public:
    SinglyLinkedList() : head(nullptr) {}

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    void insertAtStart(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (!head) { head = newNode; return; }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }

    void insertAfter(int pos, int val) {
        Node* temp = head;
        for (int i = 0; temp && i < pos; i++) temp = temp->next;
        if (!temp) { cout << "Position out of range\n"; return; }
        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    int search(int key) {
        Node* temp = head;
        int pos = 0;
        while (temp) {
            if (temp->data == key) return pos;
            temp = temp->next;
            pos++;
        }
        return -1;
    }

    int countNodes() {
        int count = 0;
        Node* temp = head;
        while (temp) { count++; temp = temp->next; }
        return count;
    }

    int sumOfNodes() {
        int sum = 0;
        Node* temp = head;
        while (temp) { sum += temp->data; temp = temp->next; }
        return sum;
    }

    void deleteFromStart() {
        if (!head) return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void deleteFromEnd() {
        if (!head) return;
        if (!head->next) { delete head; head = nullptr; return; }
        Node* temp = head;
        while (temp->next->next) temp = temp->next;
        delete temp->next;
        temp->next = nullptr;
    }

    void deleteAfter(int pos) {
        Node* temp = head;
        for (int i = 0; temp && i < pos; i++) temp = temp->next;
        if (!temp || !temp->next) { cout << "Position out of range\n"; return; }
        Node* delNode = temp->next;
        temp->next = delNode->next;
        delete delNode;
    }
};
int main() {
    SinglyLinkedList list;
    int choice, val, pos;

    do {
        cout << "\n--- Menu ---\n";
        cout << "1. Insert at Start\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert After Position\n";
        cout << "4. Display\n";
        cout << "5. Search\n";
        cout << "6. Count Nodes\n";
        cout << "7. Sum of Nodes\n";
        cout << "8. Delete from Start\n";
        cout << "9. Delete from End\n";
        cout << "10. Delete After Position\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: cout << "Enter value: "; cin >> val; list.insertAtStart(val); break;
            case 2: cout << "Enter value: "; cin >> val; list.insertAtEnd(val); break;
            case 3: cout << "Enter position and value: "; cin >> pos >> val; list.insertAfter(pos, val); break;
            case 4: list.display(); break;
            case 5: cout << "Enter key: "; cin >> val; cout << "Position: " << list.search(val) << endl; break;
            case 6: cout << "Count: " << list.countNodes() << endl; break;
            case 7: cout << "Sum: " << list.sumOfNodes() << endl; break;
            case 8: list.deleteFromStart(); break;
            case 9: list.deleteFromEnd(); break;
            case 10: cout << "Enter position: "; cin >> pos; list.deleteAfter(pos); break;
        }
    } while (choice != 0);

    return 0;
}

