/*
## 530. Minimum Absoulte difference in BST ##


# Problem Link - 
https://leetcode.com/problems/minimum-absolute-difference-in-bst/description/?envType=study-plan-v2&envId=top-interview-150

# Problem Statement -
Given the root of a Binary Search Tree (BST), return the minimum absolute difference between the values of any two different nodes in the tree.



# Query/ Code - 
*/
// TC - O(N)
// SC - O(1)

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
    int diff = INT_MAX;
    int prev = INT_MAX;
    int getMinimumDifference(TreeNode* root) {
        if(!root) return diff;
        int left = getMinimumDifference(root->left);
        diff = min (diff, abs(prev - root->val));
        prev = root->val;
        int right = getMinimumDifference(root->right);
        return min(min(right, left), diff);
    }
};