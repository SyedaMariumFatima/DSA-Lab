#include<iostream>
using namespace std;

void shellSort(int* a,int n){
    for(int g=n/2; g>0; g/=2){
		//for(int i=0; i<n; i++) cout<<a[i]<<" ";
    	for(int j=g; j<n; j++){
			int t=a[j], r=j;
			while(r>=g && a[r-g]>t)
			{
				a[r]=a[r-g];
				r-=g;
			}
			a[r]=t;
		}
    }
}
int main(){
    int n;
    cin>>n;
    int* a=new int[n];
    for(int i=0; i<n; i++) cin>>a[i];
    shellSort(a,n);
    for(int i=0; i<n; i++) cout<<a[i]<<" ";
}
//Shell sort outperforms insertion sort because it eliminates the "long-distance shift" problem by allowing elements to swap over large gaps rather than moving one adjacent position at a time
