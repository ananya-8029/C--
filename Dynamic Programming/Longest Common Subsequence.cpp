#include <bits/stdc++.h>
using namespace std;

//Problem statement: We are provided with two strings of n and m lengths. We have to find the length of the longest common subsequence in both the strings.

//Difference between substring and subsequence is that substring of a string is continuous while subsequence can be discontinuous

int recursiveApproach(string x, string y, int n, int m){
    //Base Condition
    if(n==0 || m==0){
        return 0;
    }

    //Choice Diagram
    if(x[n-1] == y[m-1]){
        //if the last character of both the string is same
        return 1+recursiveApproach(x, y, n-1, m-1);
    }
    else{
        //if both are not same then it is possible that the last character of one of the string might be equal with the second last character of the another string so we make two recursive calls. In one we reduce first string's length and in second we reduce second string's length

        return max(recursiveApproach(x, y, n-1, m),recursiveApproach(x, y, n, m-1));
    }
}

int memoizedApproach(string x, string y, int n, int m, vector<vector<int>> t){
    //Base Condtion
    if(n==0 || m==0)
        return 0;

    //Memoization
    if(t[n][m] != -1){
        return t[n][m];
    }

    if(x[n-1] == y[m-1]){
        return t[n][m] = 1+memoizedApproach(x, y, n-1, m-1, t);
    }
    else{
        return t[n][m] = max(memoizedApproach(x, y, n-1, m, t),memoizedApproach(x, y, n, m-1, t));
    }
}

void topDownApproach(string x, string y, int n, int m){
    //step i: Create a table of n+1 rows and m+1 columns
    vector<vector<int>> t (n+1, vector<int>(m+1));

    //step ii: Initialization of table
    for(int i=0; i<n+1;i++){
        for(int j=0; j<m+1;j++){
            t[0][j]=0;
            t[i][0]=0;
        }
    }

    //step iii: Evaluate the rest of the problems
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){

            if(x[i-1] == y[j-1]){
                t[i][j] = 1+t[i-1][j-1];
            }
            else{
                t[i][j] = max(t[i-1][j],t[i][j-1]);
            }
        }
    }

    cout<<t[n][m];
}

int main(){
    //Inputs
    string x="abcdgh";
    string y="abedfhr";

    int n=x.size();
    int m=y.size();

    //This was a Recursive Approach for the problem.
    cout<<recursiveApproach(x,y,n,m);

    //now using memoized DP i.e recursive calls + table

    //Initialization of table
    vector<vector<int>> t (n+1, vector<int> (m+1, -1));
    cout<<memoizedApproach(x,y,n,m,t);

    //Top down Approach or The Real Dynamic Programming
    topDownApproach(x, y, n, m);
    return 0;
}