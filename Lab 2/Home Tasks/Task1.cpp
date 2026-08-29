#include <iostream>
using namespace std;

class SafeArray{
    int rows, col;
    int** m;
    public:
    SafeArray(int r, int c){
        rows=r;
        col=c;
        m=new int*[rows];
        for(int i=0; i<rows; i++) m[i]=new int[col];
    }

    ~SafeArray(){
        for(int i=0; i<rows; i++) delete[] m[i];
        delete[] m;
    }

    void set(int r, int c, int v){
        if(r<0 || r>=rows || c<0 || c>=col) cout<<"boundary error"<<endl;
        else m[r][c]=v;
    }

    int get(int r, int c){
        if(r<0 || r>=rows || c<0 || c>=col) {
            cout<<"boundary error"<<endl;
            return -1;
        }
        return m[r][c];
    }

    void display(){
        for(int i=0; i<rows; i++){
            for(int j=0; j<col; j++){
                cout<<m[i][j]<<"   ";
            }
            cout<<endl;
        }
    }
};
int main() {
    int s=4;
    SafeArray m(4,4);
    for(int i=0; i<s; i++){
            for(int j=0; j<s; j++){
                m.set(i,j, (i+1)*(j+1));
            }
        }
    m.display();
    int a=m.get(-1,3);
    int b=m.get(3, 10);
    int c=m.get(4, 0);
    return 0;
}
