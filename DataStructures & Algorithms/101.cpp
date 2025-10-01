/*
## 101. Symmetric Tree ##


# Problem Link - 
https://leetcode.com/problems/symmetric-tree/description/?envType=study-plan-v2&envId=top-interview-150

# Problem Statement -
Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).


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
    bool check(TreeNode* left, TreeNode* right){
        if(!left || !right) return left == right;
        if(left->val != right->val) return false;
        return check(left->left, right->right) && check(left->right, right->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(!root) return root;
        return check(root->left, root->right);
    }
};