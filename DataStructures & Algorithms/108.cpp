/*
## 108. Convert Sorted array to Binary Search Tree ##


# Problem Link - 
https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/?envType=study-plan-v2&envId=top-interview-150

# Problem Statement -
Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree.


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
    TreeNode* constructTree(vector<int>& nums, int low, int high){
        int mid = low + (high-low)/2;
        if(low <= high){
            TreeNode *root = new TreeNode(nums[mid]);
            root->left = constructTree(nums, low, mid-1);
            root->right = constructTree(nums, mid+1, high);
            return root;
        }
        return NULL;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
       int n = nums.size();
       return constructTree(nums, 0, n-1); 
    }
};