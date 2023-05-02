#include <bits/stdc++.h>
using namespace std;

void merge(int arr[],int s,int e){
    int mid=(s+e)/2;

    int len1=mid-s+1;
    int len2=e-mid;

    int arr1[len1];
    int arr2[len2];

    int mainArrayindex=s;
    for(int i=0;i<len1;i++){
        arr1[i]=arr[mainArrayindex++];
    }
    mainArrayindex=mid+1;
    for(int i=0;i<len2;i++){
        arr2[i]=arr[mainArrayindex++];
    }

    //merging two sorted arrays
    int index1=0;
    int index2=0;
    mainArrayindex=s;
    while(index1<len1&&index2<len2){

        if(arr1[index1]<arr2[index2]){
            arr[mainArrayindex++]=arr1[index1];
            index1++;
        }
        else{
            arr[mainArrayindex++]=arr2[index2];
            index2++;
        }
    }
    while(index1<len1){
        arr[mainArrayindex++]=arr1[index1++];
    }
    while(index2<len2){
        arr[mainArrayindex++]=arr2[index2++];
    }
}

void mergesort(int arr[],int start,int end){
    //base case
    if(start>=end)
        return;

    int mid=(start+end)/2;
    //left part 
    mergesort(arr,start,mid);
    //right part
    mergesort(arr,mid+1,end);

    merge(arr,start,end);
}

int main(){
    int arr[6]={5,4,1,6,2,3};
    int n=5;

    cout<<"The unsorted Array is:";
    for(int i=0;i<6;i++){
        cout<<arr[i]<<" ";
    }

    mergesort(arr,0,n);

    cout<<endl;
    cout<<"The sorted Array is:";
    for(int i=0;i<6;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}