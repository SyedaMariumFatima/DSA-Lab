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
    rectangle(const rectangle &other) {
        width = new int(*other.width);
        height = new int(*other.height);
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
        cout<<"rectangle destroyed"<<endl;
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
    //the two rectangles are no longer pointing to the same memory address, hence the data is now more secure as changing one does not change the other.
    //moreover, memory heap is not corrupted
    
    return 0;
}
