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
    rectangle r(3,5);
    r.display();
    return 0;
}
