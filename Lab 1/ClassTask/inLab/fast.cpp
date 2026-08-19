#include<iostream>
using namespace std;

class dee{
	public:
	virtual void uni()=0;
};
class wee: public dee{
	public:
	void uni(){
		cout<<"fast";
	}
};
int main(){
	
	dee* d;
	d=new wee;
	d->uni();
}
