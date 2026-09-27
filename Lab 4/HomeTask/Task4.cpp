    void reverse() {
        Node* curr = head;
        Node* temp = nullptr;
        while (curr) {
            temp = curr->prev;
            curr->prev = curr->next;
            curr->next = temp;
            curr = curr->prev;
        }
        if (temp) {
            head = temp->prev;
            tail = temp;
        }
    }
