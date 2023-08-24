#include<bits/stdc++.h>
using namespace std;

//We have to convert a strictly increasing sorted array into a height balanced Binary Search Tree

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

class Solution {
public:
    //Approach: Divide the array and call for left and for right subTree
    TreeNode* divide(vector<int>& nums, int start, int end){
        //base condition
        if(start>end){
            return NULL;
        }
        int mid = start+(end-start)/2;
        TreeNode* root = new TreeNode(nums[mid]);

        root->left=divide(nums, start, mid-1);
        root->right=divide(nums, mid+1, end);

        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int start=0,end=nums.size()-1;
        return divide(nums, start, end);
    }
};