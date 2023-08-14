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

class Solution {
public:
    void levelTraversal(TreeNode* root, unordered_map<int,vector<int>> &map, int level){
        if(root==NULL){ 
            return; 
        }

        map[level].push_back(root->val);

        levelTraversal(root->left,map,level+1);
        levelTraversal(root->right,map,level+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        if(root==NULL) return ans;

        unordered_map<int,vector<int>> map;
        levelTraversal(root,map,0);

        int i=0;
        while(i<map.size()){
            int n=map[i].size();
            ans.push_back(map[i][n-1]);
            i++;
        }
        return ans;
    }
};