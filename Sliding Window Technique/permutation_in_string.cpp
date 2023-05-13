#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n=s2.size();
        int k=s1.size();
        unordered_map<char,int>map;
        int start=0,end=0;

        for(auto i:s1){
            map[i]++;
        }

        int count=map.size();

        while(end<n){
            if(map.find(s2[end])!=map.end()){
                map[s2[end]]--;
                if(map[s2[end]]==0){
                    count--;
                }
            }

            if(end-start+1 == k){
                if(count == 0){
                    return true;
                }
                
                if(map.find(s2[start])!=map.end()){
                    map[s2[start]]++;
                    if(map[s2[start]]==1){
                        count++;
                    }
                }
                start++;
            }
            end++;
        }
        return false;
    }
};