/*
## 124. Binary Tree Maximum Path Sum ##


# Problem Link - 
https://leetcode.com/problems/binary-tree-maximum-path-sum/?envType=study-plan-v2&envId=top-interview-150

# Problem Statement -
A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.

The path sum of a path is the sum of the node's values in the path.

Given the root of a binary tree, return the maximum path sum of any non-empty path.

# Query/ Code - 
*/
// TC - O(N) 
// SC - O(H)
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
    int calculate(TreeNode* root, int& res){
        if(!root) return 0;
        int left = calculate(root->left, res);
        int right = calculate(root->right, res);
        int temp = max(root->val+max(left, right), root->val);
        int ans = max(root->val+left+right, temp);
        res = max(res, ans);
        return temp;
    }
    int maxPathSum(TreeNode* root) {
        if(!root) return 0;
        int res = INT_MIN;
        int temp = calculate(root, res);
        return res;
    }
};