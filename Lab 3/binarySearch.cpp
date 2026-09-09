#include<iostream>
using namespace std;

int binarySearch(int* a,int n, int f){
    int l=0, r=n-1, m;
    while(l<r){
    	m=l+(r-l)/2;
    	if(a[m]==f) return m;
    	if(a[m]>f) r=m-1;
    	else l=m+1;
	}
	return -1;
}
int main(){
    int n;
    cin>>n;
    int* a=new int[n];
    for(int i=0; i<n; i++) cin>>a[i];
    int f;
    cin>>f;
    cout<<binarySearch(a,n,f);
    
}
