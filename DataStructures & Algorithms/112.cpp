/*
## 112. Path Sum ##


# Problem Link - 
https://leetcode.com/problems/path-sum/?envType=study-plan-v2&envId=top-interview-150

# Problem Statement -
Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.

A leaf is a node with no children.

# Query/ Code - 
*/

// TC - O(N)
// SC - O(h)


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int summ = 0;
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        if(!root->left && !root->right && targetSum == root->val) return true;
        bool left  = hasPathSum(root->left, targetSum - root->val);
        bool right = hasPathSum(root->right, targetSum - root->val);
        return left || right;
    }
};


# Explanation
1. The node with no childrens is a leaf node.
2. we recursively call the function on smaller inputs by reducing the targetSum by root->val. 
3. On the leaf node, we check if the targetsum == root->value thus by ensuring it matches with the path sum. then returing the call stack with true from there onwards
