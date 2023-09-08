#include<bits/stdc++.h>
using namespace std;

//Binary Search is an optimised and rather the fastest way to search an element in an array.We are able to search an element in an array in log n time.


void binarySearch(vector<int> &arr, int target){
    //This is a simple implementation of how Binary search actually works.
    int start=0;
    int end=arr.size()-1;

    int flag=0;

    while(start<=end){
        int mid=start+(end-start)/2;

        if(arr[mid]==target){
            flag=1;
            break;
        }
        else if(arr[mid]>target){
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }
    if(flag){
        cout<<"Target is present"<<endl;
    }
    else{
        cout<<"Target not present"<<endl;
    }
}

//Here we have to find the first occurence of the target in the array. This implies that there are duplicate elements in it.
int firstOccurence(vector<int> &arr, int target){
    int start=0;
    int end=arr.size()-1;

    int index=-1;

    while(start<=end){
        int mid=start+(end-start)/2;

        if(arr[mid]==target){
            //this means that we found one occurence which might be first or any other
            //store the index
            index=mid;

            //if it might not be the first index then agr ek occurence mila hai then this give us a idea ki first occurence uske left me hi hoga to hum left array ko consider krte hai
            end=mid-1;
        }
        else if(arr[mid]>target){
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }

    cout<<"The First Occurence of "<<target<<" is at index "<<index<<endl;
    //Time Compexity: O(log n)
    return index;
}

//Here we have to find the last occurence of the target in the array. This implies that there are duplicate elements in it.
int lastOccurence(vector<int> &arr, int target){
    int start=0;
    int end=arr.size()-1;

    int index=-1;

    while(start<=end){
        int mid=start+(end-start)/2;

        if(arr[mid]==target){
            //this means that we found one occurence which might be last or any other
            //store the index
            index=mid;

            //if it might not be the last index then agr ek occurence mila hai then this give us a idea ki last occurence uske right me hi hoga to hum right array ko consider krte hai
            start=mid+1;
        }
        else if(arr[mid]>target){
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }

    cout<<"The Last Occurence of "<<target<<" is at index "<<index<<endl;
    return index;
    //Time Compexity: O(log n)
}

int main(){
    vector<int> arr{2,4,6,8,10,12,14};
    int target=13;
    //Implementation of Binary Search
    binarySearch(arr,target);

    //We also have pre-defined function for Binary Search contained in <algorithm> header file
    binary_search(arr.begin(),arr.end(),target);

    //Variation 1
    vector<int> arr{2,4,4,4,10,12,14};
    target=4;
    int first=firstOccurence(arr, target); 

    //Variation 2
    vector<int> arr{2,4,4,4,10,12,14};
    target=4;
    int last=lastOccurence(arr, target); 

    //Variation 3
    int totalOccurence=last-first+1;  //Time Complexity: log n
    return 0;
}