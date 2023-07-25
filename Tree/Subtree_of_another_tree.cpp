#include <bits/stdc++.h>
using namespace std;

/*Program to find whether the subtree given is identical with any of the subtree of the main binary tree given*/

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
    /*Recursive Approach: Just find the node in the main tree which is same as the root of the subtree then only check if they are identical or not

    We have two cases:
    
    1.if the root and the subroot are identical i.e their values are same and they are identical for left as well as for right

    2.if the left or right of the root have the subtree 
    */
    bool isSame(TreeNode *root, TreeNode *subRoot)
    {
        if (root == NULL && subRoot == NULL)
        {
            return true;
        }
        if ((root == NULL && subRoot != NULL) || (root != NULL && subRoot == NULL))
            return false;

        return (root->val == subRoot->val) && isSame(root->left, subRoot->left) && isSame(root->right, subRoot->right);
    }

    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {
        //if any of the tree has null root then they can not be identical
        if (root == NULL || subRoot == NULL)
        {
            return false;
        }

        //The if condition handles the case 1 where the root of the tree and subtree are identical or not, if yes the we have the answer
        if (isSame(root, subRoot))
            return true;

        //this line handles case 2 where either the left of the tree contains the subtree or the right of the tree
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};