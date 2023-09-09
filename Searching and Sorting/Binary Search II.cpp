#include<bits/stdc++.h>
using namespace std;

//1. GFG Practice Ques to find the square root of a number using Binary Search
class Solution{
  public:
    long long int floorSqrt(long long int x) 
    {
        // Your code goes here
        long long int ans;
        int start=0;
        int end=x;
        
        while(start<=end){
            
            long long int mid=start+(end-start)/2;
            long long int num=mid*mid;
            if(num<x){
                ans=mid;
                start=mid+1;
            }
            else if(num>x){
                end=mid-1;
            }
            else{
                return mid;
            }
        }
        return ans;
    }
};

//2. Binary search on a nearly sorted array
//Problem Statement: In Nearly Sorted ith number might be at i-1 or i or i+1 position.
class Solution{
  public:
    int nearlySortedArray(vector<int> &arr, int target) 
    {
        //arr: [10,3,40,20,50,80,70]
        int start=0;
        int end=arr.size()-1;

        while(start<=end){
            int mid=start+(end-start)/2;

            if(arr[mid]==target){
                return mid;
            }
            if(mid-1<=start && arr[mid-1]==target){
                return mid-1;
            }
            if(mid+1>=end && arr[mid+1]==target){
                return mid+1;
            }

            if(arr[mid]<target){
                start=mid+2;
            }

            if(arr[mid]>target){
                end=mid-2;
            }
        }
        return -1;
    }
};

//3. Division of two numbers using Binary Search
class Solution {
public:
    int divide(int dividend, int divisor) {
        bool isNegative=false;
        if((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0)){
            isNegative=true;
        }
        if(dividend < 0 && divisor < 0){
            isNegative=false;
        }

        if(dividend <= INT_MIN){
            dividend=INT_MAX;
        }

        divisor=abs(divisor);
        dividend=abs(dividend);

        int start=0;
        int end=dividend;
        int ans;

        while(start<=end){
            long int mid=start+(end-start)/2;
            if(mid*divisor == dividend){
                ans=mid;
                break;
            }
            if(mid*divisor < dividend){
                ans=mid;
                start=mid+1;
            }
            if(mid*divisor > dividend){
                end=mid-1;
            }
        }
        if(ans >= INT_MAX){
            return INT_MIN;
        }
        if(ans <= INT_MIN){
            return INT_MAX;
        }
        if(isNegative)
            return -ans;
        else 
            return ans;
    }
};

//4. Find the element with odd occurence
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int start=0;
        int end=nums.size()-1;
        while(start<end){
            int mid=start+(end-start)/2;
            //index is even 
            if(mid%2==0){
                if(mid+1 <= end && nums[mid]==nums[mid+1]){
                    start=mid+2;
                }
                else{
                    end=mid;
                }
            }
            //index is odd
            else{
                if(mid-1 >= start && nums[mid]==nums[mid-1]){
                    start=mid+2;
                }
                else{
                    end=mid-1;
                }
            }
        }
        return nums[end];
    }
};

