#include <bits/stdc++.h>
using namespace std;

// We need to find out the average of each level in an array.

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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double>avg;
        if(root==NULL){
            return avg;
        }
        double average;
        long long sum;
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            sum=0;
            int n=q.size();
            double temp=n;
            while(n--){
                TreeNode* node=q.front();
                q.pop();
                sum+=node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            average=sum/temp;
            avg.push_back(average);
        }
        return avg;
    }
};