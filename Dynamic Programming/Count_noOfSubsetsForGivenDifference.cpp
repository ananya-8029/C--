#include <bits/stdc++.h>
using namespace std;

//Problem Statement: We have given an array and a number. We have to find the total number of subsets whose sum's difference is equal to the given number.
//This problem have a resemblence with the problem: Count Of Subset Sum

int countSubsets(vector<int>& arr, int sum){
    int n=arr.size();
    //step i: Create a table of n+1 rows and sum+1 columns
    vector<vector<int>> t(n+1, vector<int>(sum+1));

    //step ii: Initialization
    for(int i=0;i<n+1;i++){
        for(int j=0;j<sum+1;j++){
            if(i==0){
                t[i][j]=0;
            }
            if(j==0){
                t[i][j]=1;
            }
        }
    }

    //step iii: Evaluate other subproblems
    for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){

            //counting the total subsets of included or excluded
            if(arr[i-1] <= j){
                t[i][j] = t[i-1][j-arr[i-1]]+t[i-1][j];
            }
            else{
                t[i][j] = t[i-1][j];
            }
        }
    }

    return t[n][sum];
}

int main(){
    //Inputs
    vector<int> arr{1,1,2,3};
    int d=1;
    int n=arr.size();

    int sumArr=0;
    for(int i=0;i<n;i++){
        sumArr+=arr[i];
    }

    int sum1=(d+sumArr)/2;
    int sum2=abs(d-sum1);

    //now we can apply the same logic as we did for counting the subsets having sum equal to the given sum
    int c1=countSubsets(arr, sum1);
    int c2=countSubsets(arr, sum2);

    if(c1<c2){
        cout<<"There are "<<c1<<" subsets.";
    }
    else{
        cout<<"There are "<<c2<<" subsets.";
    }
    return 0;
}