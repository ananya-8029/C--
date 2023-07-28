#include <iostream>
#include <vector>
using namespace std;

bool sorted_array(int arr[],int n_arr){
    if(n_arr==1)
    return true;
    bool result=sorted_array(arr+1,n_arr-1);
    return (arr[0]<arr[1]&&result);
}
int main(){
    int n;
    cout<<"Enter the size: ";
    cin>>n;
    cout<<"Enter the elements:";
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    bool ans=sorted_array(a,n);
    if(ans)
        cout<<"Array is sorted";
    else
        cout<<"Array is not sorted";
    return 0;
}