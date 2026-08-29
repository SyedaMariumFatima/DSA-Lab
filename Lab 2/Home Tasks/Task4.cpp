#include <iostream>
using namespace std;

class DynamicSafeArray {
    int* arr;
    int capacity;
    int count;

public:
    DynamicSafeArray(int initialCapacity) {
        capacity = initialCapacity;
        count = 0;
        arr = new int[capacity];
    }

    ~DynamicSafeArray() {
        delete[] arr;
    }

    void pushBack(int val) {
        if(count == capacity) {
            int newCapacity = capacity * 2;
            int* temp = new int[newCapacity];
            for(int i = 0; i < count; i++)
                temp[i] = arr[i];
            delete[] arr;
            arr = temp;
            capacity = newCapacity;
            cout << "Resized to capacity " << capacity << endl;
        }
        arr[count++] = val;
    }

    void set(int pos, int val) {
        if(pos < 0 || pos >= count) {
            cout << "Boundary error in set()\n";
            return;
        }
        arr[pos] = val;
    }

    int get(int pos) {
        if(pos < 0 || pos >= count) {
            cout << "Boundary error in get()\n";
            return -1;
        }
        return arr[pos];
    }

    bool removeAt(int pos) {
        if(pos < 0 || pos >= count) {
            cout << "Boundary error in removeAt()\n";
            return false;
        }
        for(int i = pos; i < count-1; i++)
            arr[i] = arr[i+1];
        count--;
        return true;
    }

    void display() {
        cout << "Array contents: ";
        for(int i = 0; i < count; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    DynamicSafeArray dsa(2);

    for(int i = 1; i <= 6; i++)
        dsa.pushBack(i * 10);

    dsa.display();

    cout << "Removing element at index 2...\n";
    dsa.removeAt(2);
    dsa.display();

    cout << "Trying get(10): " << dsa.get(10) << endl;
    dsa.set(10, 999);

    return 0;
}
