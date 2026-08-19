#include<iostream>
using namespace std;

class student{
	public:
		int* arr;
		int size;
		int t=0;
	student(int s){
		size=s;
		arr=new int[size];
		for(int i=0; i<size; i++){
			cin>>*(arr+i);
		}
	}
	student(student &other){
		size=other.size;
		for(int i=0; i<size; i++){
			arr[i]=other.arr[i];
		}
	}
	void input(){
			for(int i=0; i<size; i++){
			cin>>*(arr+i);
		}
	}
	void display(){
		for(int i=0; i<size; i++){
			cout<<*(arr+i);
		}
	}
	void avg(){
		for(int i=0; i<size; i++){
			t+= *(arr+i);
		}
		cout<<t/size;
	}
	
	~student(){
		delete[] arr;
		cout<<endl<<"destructor called";
	}
};

int main(){
	student s(5);
	student s2(s);
	s2.input();
	s.display();
	return 0;
}
