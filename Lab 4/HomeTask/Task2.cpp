    void insertAtHead(int val) {
        Node* newNode = new Node(val);
        if (!head) head = tail = newNode;
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (!tail) head = tail = newNode;
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void insertAtPosition(int pos, int val) {
        if (pos == 0) { insertAtHead(val); return; }
        Node* temp = head;
        for (int i = 0; temp && i < pos - 1; i++) temp = temp->next;
        if (!temp || !temp->next) { insertAtEnd(val); return; }
        Node* newNode = new Node(val);
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
    }
