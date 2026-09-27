class CNode {
public:
    string data;
    CNode* next;
    CNode(string val) : data(val), next(nullptr) {}
};

class CircularLinkedList {
    CNode* head;
public:
    CircularLinkedList() : head(nullptr) {}

    void display() {
        if (!head) return;
        CNode* temp = head;
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(back to head)\n";
    }
};
