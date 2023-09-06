#include<bits/stdc++.h>
using namespace std;

//Problem Statement: We have two strings of n and m lengths and we have to find the Longest Common Subsequence.

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
    string x="abcde";
    string y="abfce";

    int n=x.size();
    int m=y.size();

    //Creation of table
    vector<vector<int>> t(n+1, vector<int>(m+1));
    //Approach: We have to evaluate the table then using the table we can easily create the longest common subsequence
    lcs(x,y,n,m,t);

    //finding the longest common subsequence
    string output;
    int i=n,j=m;
    //In this loop we iterate back to the starting index and during the iteration we see if we got the two characters equal then decrease both the pointers and also include the character to the output string
    while(i>0 && j>0){
        if(x[i-1] == y[j-1]){
            output.push_back(x[i-1]);
            i--;
            j--;
        }
        else{
            if(t[i-1][j] > t[i][j-1]){
                i--;
            }
            else{
                j--;
            }
        }
    }
    reverse(output.begin(),output.end());
    cout<<"Longest Common Subsequence is "<<output;
    return 0;
}