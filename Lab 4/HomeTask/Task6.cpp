    void append(string val) {
        CNode* newNode = new CNode(val);
        if (!head) {
            head = newNode;
            head->next = head;
            return;
        }
        CNode* temp = head;
        while (temp->next != head) temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
    }

    void insert(int pos, string val) {
        CNode* newNode = new CNode(val);
        if (pos == 0) {
            if (!head) { head = newNode; head->next = head; return; }
            CNode* tail = head;
            while (tail->next != head) tail = tail->next;
            newNode->next = head;
            tail->next = newNode;
            head = newNode;
            return;
        }
        CNode* temp = head;
        for (int i = 0; temp->next != head && i < pos - 1; i++) temp = temp->next;
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void deleteVal(string val) {
        if (!head) return;
        if (head->data == val) {
            if (head->next == head) { delete head; head = nullptr; return; }
            CNode* tail = head;
            while (tail->next != head) tail = tail->next;
            CNode* temp = head;
            head = head->next;
            tail->next = head;
            delete temp;
            return;
        }
        CNode* temp = head;
        while (temp->next != head && temp->next->data != val) temp = temp->next;
        if (temp->next->data == val) {
            CNode* delNode = temp->next;
            temp->next = delNode->next;
            delete delNode;
        }
    }

    bool search(string key) {
        if (!head) return false;
        CNode* temp = head;
        do {
            if (temp->data == key) return true;
            temp = temp->next;
        } while (temp != head);
        return false;
    }
