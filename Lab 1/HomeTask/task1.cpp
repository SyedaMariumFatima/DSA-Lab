#include <iostream>
#include <cstring>
using namespace std;

class DynamicString {
private:
    char* data;

public:
    DynamicString() {
        data = new char[1];
        data[0] = '\0';
    }

    DynamicString(const char* text) {
        if (text == nullptr) {
            data = new char[1];
            data[0] = '\0';
        } else {
            data = new char[strlen(text) + 1];
            strcpy(data, text);
        }
    }

    ~DynamicString() {
        delete[] data;
    }

    DynamicString(const DynamicString& other) {
        data = new char[strlen(other.data) + 1];
        strcpy(data, other.data);
    }

    // Copy Assignment Operator
    DynamicString& operator=(const DynamicString& other) {
       
        if (this == &other) {
            return *this;
        }

        
        delete[] data;

        data = new char[strlen(other.data) + 1];
        strcpy(data, other.data);

       
        return *this;
    }

    
    int length() const {
        return strlen(data);
    }

    void print() const {
        cout << data << endl;
    }

    // Helper
    void setChar(int index, char c) {
        if (index >= 0 && index < length()) {
            data[index] = c;
        }
    }
};

int main() {
    
    DynamicString str1("fast");
    cout << "str1: "; str1.print();

    
    DynamicString str2 = str1; 
    cout << "str2: "; str2.print();

  
    DynamicString str3;
    str3 = str1;
    cout << "str3: "; str3.print();

    
    str1.setChar(0, 'M');

    
    cout << "str1 (modified): "; str1.print();
    cout << "str2 (unaffected): "; str2.print();
    cout << "str3 (unaffected): "; str3.print();

    return 0;
}

