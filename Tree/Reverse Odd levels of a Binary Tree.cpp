#include<bits/stdc++.h>
using namespace std;

//We have to reverse the odd levels of the binary Tree

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

//This approach can be said as brute force approach where we simply do two level order traversals and plug in the reversed values in the second traversal. 
//This approach used two traversals
class Solution {
public:

    void levelOrderTraversal(TreeNode* root, unordered_map<int,vector<int>>& map, int level){

        if(root==NULL){
            return;
        }

        map[level].push_back(root->val);
        levelOrderTraversal(root->left, map, level+1);
        levelOrderTraversal(root->right, map, level+1);

    }

    void levelTraversal(TreeNode* root, unordered_map<int, vector<int>> &map, int level, int j, int &m){
        
        //base condition
        if(level==0){
            if(m<map[j].size())
                root->val=map[j][m++];
            return;
        }

        levelTraversal(root->left, map, level-1, j, m);
        levelTraversal(root->right, map, level-1, j, m);
    }

    TreeNode* reverseOddLevels(TreeNode* root) {
        if(root==NULL){
            return NULL;
        }

        //we use map data structure to store the values of the node according to their levels.
        unordered_map<int,vector<int>>map;
        //function to traverse the tree and storing the nodes values in the map
        levelOrderTraversal(root, map, 0);

        int i=1;
        while(i<map.size()){
            //reversing the the odd level vectors 
            reverse(map[i].begin(),map[i].end());
            i+=2;
        }

        //the map size would be the height of the tree
        int height=map.size();

        //Now we simply have to traverse once again the tree and put the reversed values in the odd levels of the tree. So we only see the odd levels and put the values with the help of the map.
        for(int k=1;k<height;k+=2){
            int l=0;
            levelTraversal(root, map, k, k, l);
        }

        return root;
    }
};

//This approach uses one traversal where we simply swap the left node's value with the right node's value
class Solution {
public:
    void levelOrderTraversal(TreeNode* leftNode, TreeNode* rightNode, int level){
        if(leftNode==NULL || rightNode==NULL){
            return;
        }

        if(level%2==0){
            swap(leftNode->val,rightNode->val);
        }

        levelOrderTraversal(leftNode->left, rightNode->right, level+1);
        levelOrderTraversal(leftNode->right, rightNode->left, level+1);
    }

    TreeNode* reverseOddLevels(TreeNode* root) {
        if(root==NULL){
            return NULL;
        }

        levelOrderTraversal(root->left, root->right, 0);
        return root;
    }
};