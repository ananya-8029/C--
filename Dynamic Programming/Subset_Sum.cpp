#include <bits/stdc++.h>
using namespace std;

//Problem Statement: We have an array and a SUM. We have to return bool value whether there is a subset that sums its element to the SUM or not.

//Approach: We will use Top Down Approach of the Dynamic Programming

int main(){
    //Inputs
    vector<int> arr{2,3,7,8,10};
    int sum=1;

    int n=arr.size();

    //step i: Create a table having n+1 rows and sum+1 columns
    vector<vector<bool>> t(n+1, vector<bool>(sum+1));

    //step ii: Initialization
    for(int i=0;i<n+1;i++){
        for(int j=0;j<sum+1;j++){

            if(i==0){
                t[i][j]=false;
            }

            if(j==0){
                t[i][j]=true;
            }
        }
    }

    //step iii: Evaluate for other sub problems
    //NOTE: There is similarity with the 01 knapsack problem. We simply replace weights array with the input array and W with the sum and ignoring the values array.

    for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){

            //Possibilties are there that subset exist if we include or exclude
            if(arr[i-1] <= j){
                t[i][j]= t[i-1][j-arr[i-1]] || t[i-1][j];
            }
            //no subset exist
            else{
                t[i][j]=t[i-1][j];
            }
        }
    }

    if(t[n][sum])
        cout<<"Subset do exist which evaluates to the given sum";
    else
        cout<<"Subset do not exist for the given sum";
    return 0;
}