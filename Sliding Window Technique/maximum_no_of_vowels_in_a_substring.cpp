#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxVowels(string s, int k) {
        vector<int>v(26);
        for(auto i:s){
            int ch=i;
            if( i == 'a' || i == 'e' || i == 'i' || i == 'o' || i == 'u'){
                v[ch-97]=1;
            }
            else{
                v[ch-97]=0;
            }
        }
        int n=s.size();
        
        int temp=0;
        
        for(int i=0;i<k;i++){
            int ch=s[i];
            temp+=v[ch-97];
        }
        int end=k;
        int maxVowel=temp;
        while(end<n){

            int ch1=s[end-k];
            int ch2=s[end];
            temp-=v[ch1-97];
            temp+=v[ch2-97];

            maxVowel=max(maxVowel,temp);
                
            end++;
        }  
        return maxVowel;
    }
};