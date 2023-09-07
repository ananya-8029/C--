#include<bits/stdc++.h>
using namespace std;

//Problem Statement: We are given two strings of size n and m. We have to find the length of the shortest common supersequence by merging both the strings in such a way that we get the shortest length possible.

void lcs(string x, string y, int n, int m, vector<vector<int>> &t){
    //Initialisation
    for(int i=0;i<n+1;i++){
        for(int j=0;j<m+1;j++){
            if(i==0||j==0){
                t[i][j]=0;
            }
        }
    }

    //Evaluating other sub problems
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){

            if(x[i-1] == y[j-1]){
                t[i][j]=t[i-1][j-1]+1;
            }
            else{
                t[i][j]=max(t[i][j-1],t[i-1][j]);
            }
        }
    }
}

int main(){
    //Inputs
    string x="AGGTAB";
    string y="GXTXAYB";

    int n=x.size();
    int m=y.size();

    vector<vector<int>> t(n+1, vector<int>(m+1));
    lcs(x,y,n,m,t);

    //Approach: Worst case possible here is merging the two strings as it is which will be of length n+m. Then to find the smallest possible, we noticed that there might be some characters that are common to both then we can use it only once.These common characters are termed as Longest Common Subsequence. But in worst case occurences LCS are 2 times thus substracting one extra occurence we can have Shortest Common Supersequence

    int length=(n+m)-t[n][m];

    cout<<"The length of Shortest Common Subsequence is "<<length;
    return 0;
}