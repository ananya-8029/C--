#include <bits/stdc++.h>
using namespace std;

/*Program to print level order traversal of a binary tree
--Recursive method
--Iterative method by using Queue
--Recursive method by using hashMap*/

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
    void levelOrderTraversal(TreeNode *root, int level, vector<int> &ans)
    {
        if (level == 0 || root == NULL)
        {
            return;
        }
        if (level == 1)
        {
            ans.push_back(root->val);
            return;
        }

        levelOrderTraversal(root->left, level - 1, ans);
        levelOrderTraversal(root->right, level - 1, ans);
    }

    int height(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }

        int left = height(root->left);
        int right = height(root->right);

        return max(left, right) + 1;
    }

    /*  RECURSIVE method
        Time Complexity : O(n^2)
        Space Complexity: O(h) where h is the height of the tree
    */
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;

        // Calculating the height of the tree
        int h = height(root);

        // finding node for each level
        for (int i = 1; i <= h; i++)
        {
            vector<int> levels;
            levelOrderTraversal(root, i, levels);
            ans.push_back(levels);
        }
    }

    /*  ITERATIVE method using queue data structure
        Time Complexity : O(n)
        Space Complexity: O(n)
    */
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (root == NULL)
        {
            return ans;
        }
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int n = q.size();
            vector<int> levels;
            for (int i = 0; i < n; i++)
            {
                TreeNode *node = q.front();
                q.pop();

                levels.push_back(node->val);

                if (node->left != NULL)
                    q.push(node->left);
                if (node->right != NULL)
                    q.push(node->right);
            }
            ans.push_back(levels);
        }
        return ans;
    }

    /*  Recursive method by using hashMap
        Time Complexity : O(n)
        Space Complexity: O(n)*/
    void levelOrderTraversal(TreeNode *root, int level, unordered_map<int, vector<int>> &map)
    {
        if (root == NULL)
        {
            return;
        }

        // just simply push the value of the root to the particular level in the map
        map[level].push_back(root->val);

        // for subtree just make recursive call
        levelOrderTraversal(root->left, level + 1, map);
        levelOrderTraversal(root->right, level + 1, map);
    }
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (root == NULL)
        {
            return ans;
        }
        unordered_map<int, vector<int>> map;
        levelOrderTraversal(root, 1, map);

        for (int i = 1; i <= map.size(); i++)
        {
            ans.push_back(map[i]);
        }
        return ans;
    }
};
