#include <iostream>
using namespace std;

void print(int arr[],int n){
    cout<<"this is "<<n-1<<"th iteration :";
    for(int i=0;i<6;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void bubble_sort(int arr[],int size){
    if(size==1)
        return;
    
    for(int i=0;i<size;i++){
        if(arr[i]>arr[i+1])
            swap(arr[i],arr[i+1]);
    } 
    print(arr,size);
    bubble_sort(arr,size-1);
}

int main() {
    int arr[]={8,5,1,-3,9,0};
    int n=6;
    bubble_sort(arr,n);
	// your code goes here
	return 0;
}
