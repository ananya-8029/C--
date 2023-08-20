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

//Here the binary tree contains digits from 0 to 9. Also each root to leaf path represents a number(combination of digits). We need to find the total sum of these numbers that are formed.

class Solution {
public:
    void sum(TreeNode* root, int num, int &totalSum){
        if(root==NULL){
            return;
        }

        if(root->left==NULL && root->right==NULL){
            num=num*10+root->val;
            totalSum+=num;
            return;
        }

        num=num*10+root->val;
        sum(root->left, num, totalSum);
        sum(root->right, num, totalSum);
    }

    int sumNumbers(TreeNode* root) {
        int totalSum=0;
        if(root==NULL){
            return totalSum;
        }

        int num=0;
        sum(root,num,totalSum);

        return totalSum;
    }
};