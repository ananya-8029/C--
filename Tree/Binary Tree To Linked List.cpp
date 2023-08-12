#include <bits/stdc++.h>
using namespace std;

//Program is to convert a binary tree into a linked list

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

class Solution
{
public:
    void preorderTraversal(TreeNode *root, vector<int> &preorder)
    {
        if (root == NULL)
            return;

        preorder.push_back(root->val);
        preorderTraversal(root->left, preorder);
        preorderTraversal(root->right, preorder);
    }

    //Idea is to do a preorder traversal and the simply create a tree where its left pointer is NULL and right pointer has the node.This maked the tree as 1D linked list
    void flatten(TreeNode *root)
    {
        if (root == NULL)
        {
            return;
        }

        vector<int> preorder;
        preorderTraversal(root, preorder);

        for (int i = 1; i < preorder.size(); i++)
        {
            root->left = NULL;
            root->right = new TreeNode(preorder[i]);

            root = root->right;
        }
    }
};