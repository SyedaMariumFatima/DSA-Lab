#include<iostream>
using namespace std;

class stack{
    string *arr;
    int top;
    int size;
    public:
    stack(int s){
        size=s;
        arr=new string[s];
        top=-1;
    }
    void add(string t){
        if(top==size-1){
            cout<<"stack capacity is full"<<endl;
            return;
        }
        else{
            arr[++top]=t;
        }
    }
    string removeLast(){
        if(top==-1){
            cout<<"No more tasks"<<endl;
        }
        else{
            cout<<"removed task: "<<arr[top];
            string t=arr[top];
            top--;
            return t;
        }
    }
    void display(){
        stack t(size);
        while(top!=-1){
            cout<<arr[top];
            t.add(arr[top]);
            top--;
        }
        while(top!=size){
            arr[top]=t.removeLast();
            top++;
        }
        top--;
    }
    void search(string k){
        stack t(size);
        int i=0;
        while(top!=-1){
            if(arr[top]==k){
                cout<<"found with "<<i<<" tasks above"<<endl;
                break;
            }
            t.add(arr[top]);
            top--;
            i++;
        }
        if(i==size) cout<<k<<" not found"<<endl;
        while(top!=size){
            arr[top]=t.removeLast();
            top++;
        }
        top--;
    }

};
int main(){
    int max;
    cin>>max;
    stack s(max);
    string t;
    int in;
    do{
        switch(max){
            case 1:
                getline(cin, t);
                s.add(t);
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            default:
                break;
        }
    }while(in!=5);

}
