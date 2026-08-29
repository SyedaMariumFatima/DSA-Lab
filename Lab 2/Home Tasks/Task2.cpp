#include <iostream>
using namespace std;

class JaggedArray {
    int rows;
    int* col;   // dynamic array for subjects per student
    int** arr;  // jagged array
    int* avg;   // dynamic array for averages
    int minAvg, maxAvg;

public:
    JaggedArray() {
        cout << "Enter number of students: ";
        cin >> rows;

        col = new int[rows];
        arr = new int*[rows];
        avg = new int[rows];

        for(int i = 0; i < rows; i++) {
            cout << "Enter subjects for student " << i+1 << ": ";
            cin >> col[i];
            arr[i] = new int[col[i]];

            cout << "Enter marks for student " << i+1 << ": ";
            for(int j = 0; j < col[i]; j++) 
                cin >> arr[i][j];
        }
    }

    ~JaggedArray() {
        for(int i = 0; i < rows; i++) 
            delete[] arr[i];
        delete[] arr;
        delete[] col;
        delete[] avg;
    }

    void display() {
        for(int i = 0; i < rows; i++) {
            cout << "Marks for student " << i+1 << ": ";
            for(int j = 0; j < col[i]; j++) 
                cout << arr[i][j] << " ";
            cout << endl;
        }

        for(int i = 0; i < rows; i++) {
            avg[i] = 0;
            for(int j = 0; j < col[i]; j++) 
                avg[i] += arr[i][j];
            avg[i] /= col[i];
            cout << "Student " << i+1 << " average: " << avg[i] << endl;
        }

        minAvg = maxAvg = 0;
        for(int i = 1; i < rows; i++) {
            if(avg[i] < avg[minAvg]) minAvg = i;
            if(avg[i] > avg[maxAvg]) maxAvg = i;
        }

        cout << "Highest average: Student " << maxAvg+1 
             << " | Lowest average: Student " << minAvg+1 << endl;
    }

    // r is the student index (0-based), m is the new course mark
    void addCourse(int r, int m) {
        int* temp = new int[col[r] + 1];
        for(int i = 0; i < col[r]; i++) 
            temp[i] = arr[r][i];
        temp[col[r]] = m;

        delete[] arr[r];   // free old memory
        arr[r] = temp;
        col[r] += 1;
    }
};

int main() {
    JaggedArray ja;
    ja.display();

    cout << "\nAdding new course for student 1...\n";
    ja.addCourse(0, 95);
    ja.display();

    return 0;
}
