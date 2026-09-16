#include<iostream>
using namespace std;

class node{
	public:
	int data;
	node* next;
	node(int val){
		data=val;
		
		next=NULL;
	}
};
class singly{
	public:
	node* head;
	node* tail;
	singly(){
		head=NULL;
		tail=NULL;
	}
	
	void insertAfter(int pos, int val){
		node* n=new node(val);
		node* pre;
		node* curr=head;
		for(int i=0; i<pos; i++){
			pre=curr;
			curr=curr->next;
		}
		pre->next=n;
		n->next=curr;
	}
	void insertAtTail (int val)
	{
		node * n= new node (val);
		if(head == NULL)
		{
		 	head= n;
			return;
		}
		node * temp = head;
		while(temp->next != tail)
		{
			temp = temp->next;
		}
		temp->next = n;
		n->next=tail;
		cout<<"Inserted"<<endl;
	}
	void display(){
		node* curr=head;
		while(curr!=NULL){
			cout<<curr->data<<" ";
			curr=curr->next;
		}
		cout<<endl;
	}
	void reverse(){
		node* curr=head;
		node* nxt;
		node* prev;
		while(curr!=NULL){
			nxt=curr->next;
			curr->next=prev;
			prev=curr;
			curr=nxt;
		}
		tail=head;
		head=prev;
		tail->next=NULL;
	}
	};
int main(){
	singly l;
	for(int i=0; i<6; i++) l.insertAtTail(i+1);
	l.display();
	l.reverse();
	l.display();
}
