#include<iostream>
using namespace std;

void bubbleSort(int* a,int n){
    int temp;
    for(int i=0; i<n; i++){
        for(int j=0; j<n-1; j++){
            if(a[j]>a[j+1]){
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            } 
        }
    }
}
int main(){
    int n;
    cin>>n;
    int* a=new int[n];
    for(int i=0; i<n; i++) cin>>a[i];
    bubbleSort(a,n);
    for(int i=0; i<n; i++) cout<<a[i]<<" ";
}
