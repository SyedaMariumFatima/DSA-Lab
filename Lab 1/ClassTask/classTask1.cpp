#include <iostream>
using namespace std;

int main() 
{
    int* arr;
    int n;
    cout << "Enter the number of elements";
    arr=new int[n];
    for(int i=0; i<n; i++){
        cout<<"enter element"<<i;
        cin>>*(arr+i);
    }
    int max=arr[0], min=arr[0], sum=arr[0];
    for(int i=1; i<n; i++){
        if(arr[i]>max) max=arr[i];
        else if(arr[i]<min) min=arr[i];
        sum+=arr[i];
    }
    int avg=sum/n;

    cout<<"sum:"<<sum;
    cout<<"average:"<<avg;
    cout<<"Maximum:"<<max;
    cout<<"Minimum"<<min;
    return 0;
}
