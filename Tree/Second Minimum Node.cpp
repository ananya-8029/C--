#include <bits/stdc++.h>
using namespace std;

// We need to find out the second minimum value in a binary tree. The tree has either two nodes or has no child also every root's value is the minimum of its both child's value

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
    int findSecondMinimumValue(TreeNode* root) {
        //when root is leaf node that means it has no second minimum value
        if(root->left==NULL && root->right==NULL) return -1;
        
        queue<TreeNode*>q;
        set<int>s;

        q.push(root);
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();

            s.insert(node->val);

            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }

        if(s.size()==1){
            return -1;
        }        
        auto it=s.begin();
        for(int i=1;i<2;i++){
            it++;
        }

        return *it;
    }
};