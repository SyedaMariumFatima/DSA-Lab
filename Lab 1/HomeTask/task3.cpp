#include <iostream>
using namespace std;

class DynamicArray {
    int* arr;
    int size;
    int capacity;

public:
    DynamicArray(int initialCapacity = 2) {
        capacity = initialCapacity;
        size = 0;
        arr = new int[capacity];
    }

    ~DynamicArray() {
        delete[] arr;
    }

    DynamicArray(const DynamicArray& other) {
        size = other.size;
        capacity = other.capacity;
        arr = new int[capacity];
        for(int i = 0; i < size; i++)
            arr[i] = other.arr[i];
    }

    DynamicArray& operator=(const DynamicArray& other) {
        if(this != &other) {
            delete[] arr;
            size = other.size;
            capacity = other.capacity;
            arr = new int[capacity];
            for(int i = 0; i < size; i++)
                arr[i] = other.arr[i];
        }
        return *this;
    }

    void pushBack(int value) {
        if(size == capacity) {
            capacity *= 2;
            int* temp = new int[capacity];
            for(int i = 0; i < size; i++)
                temp[i] = arr[i];
            delete[] arr;
            arr = temp;
        }
        arr[size++] = value;
    }

    int& operator[](int index) {
        if(index < 0 || index >= size) {
            cout << "Boundary error\n";
            static int dummy = -1;
            return dummy;
        }
        return arr[index];
    }

    void print() const {
        for(int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    DynamicArray d1;
    for(int i = 1; i <= 6; i++)
        d1.pushBack(i * 10);

    cout << "Array d1: ";
    d1.print();

    DynamicArray d2 = d1;
    d2[0] = 99;

    cout << "Array d1 after copy-modify: ";
    d1.print();
    cout << "Array d2 (modified copy): ";
    d2.print();

    return 0;
}

