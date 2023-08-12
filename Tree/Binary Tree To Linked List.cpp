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

//GFG SOLUTION
//Idea is to do a recursive call for left subtree and make all the left node right and all the left point to NULL.
class Solution {
public:
    void flatten(TreeNode* root) {
        //check for null or a leaf node
        if(root==NULL || root->left==NULL && root->right==NULL) return;

        //now we have to make left node null.So make all the left node to right
        if(root->left!=NULL){
            //see for the last node in the left
            flatten(root->left);

            //store the right of the node in a variale and move left valuse to right and make left as null
            TreeNode* temp=root->right;
            root->right=root->left;
            root->left=NULL;

            //now we have to move the right of the node to the last of the right node.We simply need to traverse the right from the root
            TreeNode* node=root->right;
            while(node->right!=NULL){
                node=node->right;
            }

            //we have the position where the node have to be inserted
            node->right=temp;
        }
        //now traverse for the right
        flatten(root->right);
    }
};