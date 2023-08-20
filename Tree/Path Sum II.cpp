#include<bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//Here we have to return the path from root to leaf which is equal to the targetSum

//Without backtracking
class Solution {
public:
    void sum(TreeNode* root, int s,vector<int>path,int targetSum,vector<vector<int>> &totalSum){
        if(root==NULL) {
            return;
        }

        if(root->left==NULL && root->right==NULL){
            s=s+root->val;
            path.push_back(root->val);
            if(s==targetSum){
                totalSum.push_back(path);
            }
            return;
        }
        path.push_back(root->val);
        
        s=s+root->val;

        sum(root->left,s,path,targetSum,totalSum);
        sum(root->right,s,path,targetSum,totalSum);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> totalSum;
        if(root==NULL){
            return totalSum;
        }
        vector<int>path;
        int s=0;
        sum(root,s,path,targetSum,totalSum);

        return totalSum;
    }
};


//With backtracking
class Solution {
public:
    void totalSum(TreeNode* root, int targetSum, vector<int> path, vector<vector<int>> &Sum){
        if(root==NULL){
            return;
        }

        if(root->left==NULL && root->right==NULL){
            path.push_back(root->val);
            if(targetSum==root->val){
                Sum.push_back(path);
            }
            path.pop_back();
            return;
        }

        path.push_back(root->val);
        targetSum-=root->val;
        totalSum(root->left, targetSum, path, Sum);
        totalSum(root->right, targetSum, path, Sum);
        
        //backtracking
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>Sum;
        if(root==NULL){
            return Sum;
        }

        vector<int>path;
        totalSum(root, targetSum, path, Sum);
        return Sum;
    }
};