#include<bits/stdc++.h>
using namespace std;

//A simple approach where we traverse even length of substring and odd length of substring
class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size();
        int i,j;
        int count=0;

        int k=0;
        while(k<n){
            //odd substring
            i=k;
            j=k;
            while(i>=0 && j<s.size()){
                if(s[i]==s[j]){
                    count++;
                }
                else{
                    break;
                }
                i--;
                j++;
            }
            k++;
        }

        k=0;
        while(k<n){
            //even substring
            i=k;
            j=k+1;

            if(s[i]!=s[j]){
                k++;
                continue;
            }

            while(i>=0 && j<s.size()){
                if(s[i]==s[j]){
                    count++;
                }
                else{
                    break;
                }
                i--;
                j++;
            }
            k++;
        }
        return count;
    }
};