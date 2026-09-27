    CNode* current = nullptr;

    void nextTurn() {
        if (!current) current = head;
        else current = current->next;
        cout << "Turn: " << current->data << endl;
    }

    void removePlayer(string name) {
        deleteVal(name);
        if (current && current->data == name) current = current->next;
    }
