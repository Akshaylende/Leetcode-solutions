/*
## 230. Kth Smallest Element in a BST ##


# Problem Link - 
https://leetcode.com/problems/kth-smallest-element-in-a-bst/?envType=study-plan-v2&envId=top-interview-150

# Problem Statement -
Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.



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
    int count = 0, res;
    void calculate(TreeNode* root, int k){
        if(!root) return;
        calculate(root->left, k);
        count++;
        if(k == count) {
            res = root->val;
            return;
        }
        calculate(root->right, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        calculate(root, k);
        return res;
    }
};
