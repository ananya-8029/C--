#include <bits/stdc++.h>
using namespace std;

//Program for Zigzag Traversal of a binary tree

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

    void zigzag(TreeNode* root,int level,int count,vector<int>& temp){
        if(root==NULL) return;

        if(level==0) {
            temp.push_back(root->val);
            return;
        }

        if(count%2==0){
            zigzag(root->left,level-1,count,temp);
            zigzag(root->right,level-1,count,temp);
        }
        else{
            zigzag(root->right,level-1,count,temp);
            zigzag(root->left,level-1,count,temp);
        }
    }

    int height(TreeNode* root){
        if(root==NULL) return 0;
        return max(height(root->left),height(root->right))+1;
    }

    //We can simply do level order traversal and check for even levels and odd levels. For even we must do right to left traversal and for odd left to right traversal.
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL) return ans;

        int h=height(root);

        for(int i=0;i<h;i++){
            vector<int>temp;
            //here first i keeps track for each level in recursive call and the other is used to keep track of the actual level on which we are executing the funtion.
            zigzag(root,i,i,temp);
            ans.push_back(temp);
        }
        return ans;
    }
};