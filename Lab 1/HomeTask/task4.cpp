/*

Problem:
- The compiler-generated copy constructor and assignment operator perform shallow copies.
- This means only the pointer `data` is copied, not the actual array contents.
- As a result, two Buffer objects end up sharing the same memory block.

Observed Behavior:
- Modifying one object also changes the other, since they point to the same array.
- At destruction, both objects attempt to delete[] the same memory, causing double deletion and undefined behavior.

Missing Special Member Functions:
- Copy constructor (deep copy)
- Copy assignment operator (deep copy)
*/

#include <iostream>
using namespace std;

class Buffer {
private:
    int* data;
    int length;

public:
    Buffer(int len) {
        length = len;
        data = new int[length];
        for (int i = 0; i < length; i++) data[i] = 0;
    }

    Buffer(const Buffer& other) {
        length = other.length;
        data = new int[length];
        for (int i = 0; i < length; i++)
            data[i] = other.data[i];
    }

    Buffer& operator=(const Buffer& other) {
        if(this != &other) {
            delete[] data;
            length = other.length;
            data = new int[length];
            for (int i = 0; i < length; i++)
                data[i] = other.data[i];
        }
        return *this;
    }

    void setValue(int index, int value) {
        if(index >= 0 && index < length)
            data[index] = value;
    }

    void display() const {
        for (int i = 0; i < length; i++)
            cout << data[i] << " ";
        cout << endl;
    }

    ~Buffer() {
        delete[] data;
    }
};

int main() {
    Buffer b1(5);
    b1.setValue(0, 10);
    Buffer b2 = b1;
    b2.setValue(1, 20);

    b1.display();
    b2.display();

    return 0;
}

