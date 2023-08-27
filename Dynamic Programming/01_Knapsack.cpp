#include <bits/stdc++.h>
using namespace std;

//What is a 0-1 knapsack problem?
//Here we have a sack of W capacity and an array of weights and an array of thier respective values. We need to find the maximum profit we can have by including the right weights in the sack.
//Here we have choices to make and on the basis of that choices we have to calculate maximum result this simply indicates that this is a Dynamic Programming based problem.

//Recursive Approach 
int knapsack_recursive(vector<int>& weights, vector<int>& values, int W, int n){
    //Base condition
    if(n==0 || W==0){
        return 0;
    }

    //checking whether the current weight is less than the capacity or not
    
    if(weights[n-1]<=W){ //include or exclude
        return max(values[n-1]+knapsack_recursive(weights, values, W-weights[n-1], n-1),knapsack_recursive(weights, values, W, n-1));
    }
    else{ //exclude
        return knapsack_recursive(weights, values, W, n-1);
    }
}

//Memoized Approach
//In this approach we make a 2D matrix to store the results of the sub problems of the main problem
int knapsack_memoized(vector<int>& weights, vector<int>& values, int W, int n, vector<vector<int>>& t){
    //Base condtion
    if(n==0 || W==0){
        return 0;
    }

    //In memoized version we have an advantage that we can stop the evaluation of the sub problem that has already beed evaluated by storing the results in the matrix
    //So we first check whether the current sub problem is solved earlier or not

    if(t[n][W]!=-1){ //This prevents the re evaluation of the sub problem which has been already evaluated.
        return t[n][W];
    }

    if(weights[n-1]<=W){
        //This will return the value and also store it in the matrix
        return t[n][W] = max(values[n-1]+knapsack_memoized(weights, values, W-weights[n-1], n-1, t),knapsack_memoized(weights, values, W, n-1, t));
    }
    else{
        return t[n][W] = knapsack_memoized(weights, values, W, n-1, t);
    }
}


//Top down Approach
//In top down approach we omit all recursive calls and use the tables or we can say dp to calculate the results
void topDownApproach(vector<int>& weights, vector<int>& values, int n, int W){
    //Table for storing the data
    //size = n+1 * W+1
    vector<vector<int>> dp;

    //the base condition of the recursion is converted to initialization in this approach
    //initializing the 0th row and 0th column of the table with the base values, here the base value is 0
    //NOTE: There can be any base value according to the given question
    for(int i=0;i<n+1;i++){
        for(int j=0;j<W+1;j++){
            if(i==0 || j==0){
                dp[i][j]=0;
            }
        }
    }

    //Now omitting the recursive calls
    for(int i=1;i<n+1;i++){
        for(int j=1;j<W+1;j++){

            if(weights[i-1]<=j){
                dp[i][j]=max(values[i-1]+dp[i-1][j-weights[i-1]], dp[i-1][j]);
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }

    cout<<"The maximum profit we can attain is:"<<dp[n][W];
}



int main(){
    vector<int>values{1, 2, 3},weights{4, 5, 1};
    int W=4;
    int n=weights.size();

    int result1=knapsack_recursive(weights, values, W, n);
    cout<<result1<<endl;


    //2D matrix where we initialized all n rows with a vector of W size and initialized all the elements of with -1
    vector<vector<int>> t (n+1, vector<int> (W+1, -1));
    int result2 = knapsack_memoized(weights, values, W, n, t);
    cout<<result2<<endl;


    topDownApproach(weights, values, n, W);
    return 0;
}

