#include <bits/stdc++.h>
using namespace std;

//Problem Statement: We have two strings on length n and m. We need to find the length of the longest common substring in both the strings.

//This problem is a variation of Longest Common Subsequence Problem. The difference is that we need to find a substring which is always continuous.

int main(){
    //Inputs
    string x="abcde";
    string y="abfce";

    int n=x.size();
    int m=y.size();

    //step i: Create a table of n+1 rows and m+1 columns
    vector<vector<int>> t(n+1, vector<int> (m+1));

    //step ii: Initialization
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
                t[i][j] = 0;
            }
        }
    }

    cout<<t[n][m];

    return 0;
}