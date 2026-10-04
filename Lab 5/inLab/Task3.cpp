#include<iostream>
using namespace std;
class node{
    public:
    char val;
    node* next;
    node(int v){
        val=v;
        next=NULL;
    }
};
class stack{
    node* top;
    public:
    stack(){
        top=NULL;
    }
    void push(char v){
        node* n=new node(v);
        n->next=top;
        top=n;
    }
    char pop(){
        if(top==NULL){
            return '0';
        }
        char t=top->val;
        node* temp=top;
        top=top->next;
        delete temp;
        return t;
    }
    char peek(){
        return top->val;
    }
    bool empty(){
        return top==NULL;
    }
};
int sig(char c){
    if(c=='^') return 3;
    if(c=='*' || c=='/') return 2;
    else return 1;
}
string inToPost(string in){
    string post="";
    stack op;
    int n=in.length();
    int i=0;
    while(i<n){
        if((in[i]>='a'&&in[i]<='z')||(in[i]>='A'&&in[i]<='Z')) post+=in[i];
        else if(in[i]=='(') op.push(in[i]);
        else if(in[i]==')'){
            while(!op.empty() && op.peek()!='('){
                char temp=op.pop();
                post+=temp;
            }
            if(op.peek()=='(') op.pop();
        }
        else{
            while(!op.empty() && sig(op.peek())>sig(in[i])){
                char t=op.pop();
                post+=t;
            }
            op.push(in[i]);
        }
        i++;
    }
    while(!op.empty()){
            char t=op.pop();
            post+=t;
        }
    return post;
}
