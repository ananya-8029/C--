#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool validPalindrome(string s) {
        int i=0;
        int j=s.size()-1;

        while(i<=j){
            if(s[i]!=s[j]){
                break;
            }
            i++;
            j--;
        }

        if(i>j){
            return true;
        }
        //here s1 and s2 are the substrings we form after removal of ith position from string s for s1 and after removal of jth position from string s for s2
        string s1=s;
        string s2=s;
        s1=s1.erase(i,1);
        s2=s2.erase(j,1);
        
        int flag1=0;
        i=0;
        j=s1.size()-1;
        while(i<=j){
            if(s1[i]!=s1[j]){
                flag1=1;
                break;
            }
            i++;
            j--;
        }

        int flag2=0;
        i=0;
        j=s2.size()-1;
        while(i<=j){
            if(s2[i]!=s2[j]){
                flag2=1;
                break;
            }
            i++;
            j--;
        }
        
        //if s1 is palindrome or s2 is palindrome then we can say that we can delete one letter to make string s a valid palindrome.

        //flag1 represents whether s1 is palindrome or not and flag2 represents whether s2 is palindrome or not
        if(flag1 && flag2){
            return false;
        }

        return true;
    }
};