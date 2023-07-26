#include <bits/stdc++.h>
using namespace std;

// We have root of two binary trees and we need to merge them either by creating a new binary tree or by modifying any of the tree

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
    //here we can do preorder traversal and modify the first tree
    TreeNode *merge(TreeNode *root1, TreeNode *root2)
    {
        if (root1 == NULL && root2 == NULL)
        {
            return NULL;
        }
        if (root1 != NULL && root2 != NULL)
        {
            root1->val = root1->val + root2->val;
        }
        if (root1 == NULL && root2 != NULL)
        {
            return root2;
        }

        if (root1 != NULL && root2 == NULL)
        {
            return root1;
        }

        root1->left = merge(root1->left, root2->left);
        root1->right = merge(root1->right, root2->right);

        return root1;
    }

    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
    {
        if (root1 == NULL && root2 == NULL)
        {
            return root1;
        }
        return merge(root1, root2);
    }
};