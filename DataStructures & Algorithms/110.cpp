/*
## 110. Balanced Binary Tree ##


# Problem Link - 
https://leetcode.com/problems/balanced-binary-tree/description/?envType=problem-list-v2&envId=tree

# Problem Statement -
Given a binary tree, determine if it is height-balanced.



# Query/ Code - 
*/

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
    int help(TreeNode* root)
    {
        
        if(!root )
        {
            return 0;
        }
        return 1+max(help(root-> left), help(root->right));
    }
    bool isBalanced(TreeNode* root) {
        if(!root)
        {
            return true;
        }
        int diff =  (abs(help(root->left) - help(root-> right)));
        if(diff>1)
        {
            return false;
        }
        return isBalanced(root-> left) && isBalanced(root->right);
    }
};