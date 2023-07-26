#include <bits/stdc++.h>
using namespace std;

//Program is to construct a string containing parantheses from a binary tree 

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
    string tree2str(TreeNode *root)
    {
        //returns nothing if root is null
        if (root == NULL)
        {
            return "";
        }

        if (root->left == NULL && root->right == NULL)
        {
            return to_string(root->val);
        }

        if (root->left != NULL && root->right == NULL)
        {
            return to_string(root->val) + "(" + tree2str(root->left) + ")";
        }

        //we simply do preorder traversal and addinf braces at appropriate position
        return to_string(root->val) + "(" + tree2str(root->left) + ")" + "(" + tree2str(root->right) + ")";
    }
};