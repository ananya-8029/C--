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
    bool dfsTraversal(TreeNode* root, TreeNode* node, vector<TreeNode*>& path){
        
        //base condition
        if(root==NULL) return false;

        //checking if the current root is the node
        if(root->val==node->val) {
            path.push_back(root);
            return true;
        }
        
        path.push_back(root);

        bool left = dfsTraversal(root->left, node, path);
        bool right = dfsTraversal(root->right, node, path);
        
        //this tells whether the node is present in left or in right or not present
        if(right||left){
            return true;
        }

        //if the node is neither present in the left and right then we simply remove the node from our data structure
        path.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*>path1,path2;

        dfsTraversal(root, p, path1);
        dfsTraversal(root, q, path2);
        int i=0;
        while(i<path1.size() && i<path2.size()){
            if(path1[i]->val != path2[i]->val){
                break;
            }
            i++;
        }
        return path1[i-1];
    }
};