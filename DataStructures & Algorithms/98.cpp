/*
## 98. Validate Binary Search Tree ##


# Problem Link - 
https://leetcode.com/problems/validate-binary-search-tree/?envType=study-plan-v2&envId=top-interview-150

# Problem Statement -
Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

The left subtree of a node contains only nodes with keys strictly less than the node's key.
The right subtree of a node contains only nodes with keys strictly greater than the node's key.
Both the left and right subtrees must also be binary search trees.

# Query/ Code - 
*/
// TC - O(N)
// SC - O(N)
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
    vector<int> traversal;
    void inorder(TreeNode* root){
        if(!root) return;
        inorder(root->left);
        traversal.push_back(root->val);
        inorder(root->right);
    }
    bool isValidBST(TreeNode* root) {
        inorder(root);
        int i = 0 , j = i+1;
        while(j < traversal.size()){
            if(traversal[i] >= traversal[j]) return false;
            i++, j++;
        } 
        return true;
    }
};




// optimized approach 

// shrinking boundaries and expanding min range
//TC - O(N)
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
    bool check(TreeNode* root, long long mina, long long maxa){
        if(!root) return true;
        if(root->val <= mina || root->val >= maxa) return false;
        return check(root->left, mina, root->val) && check(root->right, root-> val, maxa);
    }
    bool isValidBST(TreeNode* root) {
        return check(root, LLONG_MIN, LLONG_MAX);
    }
};

# Explanation- 
1. so the left side of the BST should have less values than the root and the right side should have greater values than the root.
2. check for root value should greater than left minima and should not exceed the right maxima 
3. a bounded range will ensure that the bst is valid or not. 