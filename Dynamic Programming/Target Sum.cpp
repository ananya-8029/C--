#include<bits/stdc++.h>
using namespace std;

//LEETCODE 494
class Solution {
public:

    int countSubsets(vector<int>& nums, int sum){
        int n=nums.size();
        vector<vector<int>> t(n+1, vector<int> (sum+1));

        for(int i=0;i<n+1;i++){
            for(int j=0;j<sum+1;j++){
                if(i==0){
                    t[i][j]=0;
                }
                if(j==0){
                    t[i][j]=1;
                }
            }
        }

        for(int i=1;i<n+1;i++){
            for(int j=0;j<sum+1;j++){
                
                if(nums[i-1]<=j){
                    t[i][j]=t[i-1][j-nums[i-1]]+t[i-1][j];
                }
                else{
                    t[i][j]=t[i-1][j];
                }
            }
        }

        return t[n][sum];
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int sum=0;

        for(int i=0;i<n;i++){
            sum+=nums[i];
        }

        if((sum+target)%2==1 || sum<abs(target))
            return 0;

        int sum1=(sum+target)/2;
        int sum2=abs(target-sum1);

        int c1=countSubsets(nums,sum1);

        return c1;
        
    }
};