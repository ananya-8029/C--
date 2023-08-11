#include<bits/stdc++.h>
using namespace std;

//Program is to construct a binary tree from travesals.

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

//Binary Tree from Preorder Traversal and Inorder Traversal
class Solution {
public:

    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int start, int end, int &preIndex, unordered_map<int,int> &map){
        if(start>end) return NULL;

        TreeNode* node=new TreeNode(preorder[preIndex++]);
        int index=map[node->val];

        node->left=build(preorder, inorder, start, index-1, preIndex,map);
        node->right=build(preorder, inorder, index+1, end, preIndex,map); 

        return node;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //preIndex variable is responsible for travesal in preorder array to get all the roots
        int preIndex=0;
        //map is used to know the index of the root in inorder travesal
        unordered_map<int,int>map;
        for(int i=0;i<inorder.size();i++){
            map[inorder[i]]=i;
        }
        int start=0;
        int end=inorder.size()-1;
        return build(preorder,inorder,start,end,preIndex,map);
    }
};

//Binary Tree from Postorder Traversals and Inorder Traversal
class Solution {
public:
    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int start, int end, unordered_map<int,int> &map, int &postIndex){
        if(start>end) return NULL;
        if(postIndex<0) return NULL;

        TreeNode* root=new TreeNode(postorder[postIndex--]);
        int index=map[root->val];

        root->right=build(inorder, postorder, index+1, end, map, postIndex);
        root->left=build(inorder, postorder, start, index-1, map, postIndex);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        //map is used to know the index of the root in inorder traversal
        unordered_map<int,int>map;
        for(int i=0;i<inorder.size();i++){
            map[inorder[i]]=i;
        }
        int postIndex=postorder.size()-1;
        return build(inorder, postorder, 0, inorder.size()-1, map, postIndex);
    }
};