/*
## 99. Recover Binary Search Tree ##


# Problem Link - 
https://leetcode.com/problems/recover-binary-search-tree/description/?envType=problem-list-v2&envId=tree


# Problem Statement -
You are given the root of a binary search tree (BST), where the values of exactly two nodes of the tree were swapped
by mistake. Recover the tree without changing its structure.


# Query/ Code - 
*/

// TC - O(N)
// SC - O(log(H))

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
    TreeNode *prev;
    TreeNode *first;
    TreeNode *second;
    TreeNode *last;
public:
    void inorder(TreeNode* root){
        if(!root) return;
        inorder(root->left);
        if(prev && root->val < prev->val){
            if(!first){
                first = prev;
                second = root;
            }
            else last = root;
        }
        prev = root;
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        inorder(root);
        first && last ? swap(first->val, last->val) : swap(first->val, second->val);
    }
};



# Explanation -  
1. we have initialized three variables here first, second and last to track the inorder sequence
2. prev to track root or first element of the sequence, first, second and last to track the violations
3. first and second would be from first violation and the last would be optional if there will be two violations
4. In the end, checking if last is valid or not else then swapping first and second only.