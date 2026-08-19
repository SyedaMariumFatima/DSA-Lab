#include <iostream>
using namespace std;

class rectangle{
    int* width;
    int* height;
    public:
    rectangle(int w, int h){
        width=new int(w);
        height=new int(h);
    }
    int* getWidth() {return width;}
    void setWidth(int w){*width=w;}
    int area(){
        return (*width)*(*height);
    }
    void display(){
        cout<<"width: "<<*width<<endl;
        cout<<"height: "<<*height<<endl;
        cout<<"area: "<<area()<<endl;
    }
    ~rectangle(){
        delete[] width;
        delete[] height;
        cout<<"rectangle destroyed";
    }
};
int main() 
{
    rectangle r1(4,5);
    rectangle r2=r1;
    cout<<r1.getWidth()<<endl;
    cout<<r2.getWidth()<<endl;
    r2.setWidth(8);
    r1.display();
    //This triggers Undefined Behavior (UB), meaning the program could crash instantly, corrupt its memory heap, or introduce critical security vulnerabilities.
    
    return 0;
}
