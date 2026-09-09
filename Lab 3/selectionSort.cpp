#include<iostream>
using namespace std;

void selectionSort(int* a,int n){
    for(int i=0; i<n-1; i++){
    	int min=i;
        for(int j=i+1; j<n; j++){
            if(a[min]>a[j]){
                min=j;
            } 
        }
        int temp=a[i];
        a[i]=a[min];
        a[min]=temp;
    }
}
int main(){
    int n;
    cin>>n;
    int* a=new int[n];
    for(int i=0; i<n; i++) cin>>a[i];
    selectionSort(a,n);
    for(int i=0; i<n; i++) cout<<a[i]<<" ";
}
