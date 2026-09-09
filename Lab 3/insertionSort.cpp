#include<iostream>
using namespace std;

void insertionSort(int* a,int n){
    for(int i=1; i<n; i++){
    	int j=i-1;
    	int k=a[i];
    	while(j>=0 && a[j]>k){
    		a[j+1]=a[j];
    		j--;
		}
		a[j+1]=k;
    }
}
int main(){
    int n;
    cin>>n;
    int* a=new int[n];
    for(int i=0; i<n; i++) cin>>a[i];
    insertionSort(a,n);
    for(int i=0; i<n; i++) cout<<a[i]<<" ";
}
