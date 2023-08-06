#include<bits/stdc++.h>
using namespace std;

//In this program we find out whether two integers are cousins or not in the binary tree. Cousins are said to be at same level with different parents.


//Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:

    void findCousin(TreeNode* root, int x, int y, int level, unordered_map<int,vector<int>>& map){

        if(root==NULL) return;

        //if root-left or root->right are equal to x or y then store its root(parent node) and its corresponding level
        if(root->left!=NULL){
            if(root->left->val == x){
                map[x].push_back(root->val);
                map[x].push_back(level+1);
            }
            if(root->left->val == y){
                map[y].push_back(root->val);
                map[y].push_back(level+1);
            }
        } 
        if(root->right!=NULL){
            if(root->right->val == x){
                map[x].push_back(root->val);
                map[x].push_back(level+1);
            }
            if(root->right->val == y){
                map[y].push_back(root->val);
                map[y].push_back(level+1);
            }
        }

        findCousin(root->left, x, y, level+1, map);
        findCousin(root->right, x, y, level+1, map);
    }


    bool isCousins(TreeNode* root, int x, int y) {
        if(root==NULL) return false;

        if(root->val == x || root->val == y) return false;

        //creating a map to store each variable's parent and its level
        unordered_map<int,vector<int>>map;

        //level order traversal
        findCousin(root,x,y,0,map);

        //checking if the variable's parent are not same but the level is same then we can say they are same
        if((map[x][0] != map[y][0]) && map[x][1] == map[y][1]) return true;

        return false;
    } 
};