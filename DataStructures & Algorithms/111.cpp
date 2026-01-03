/*
## 111. minimum Depth of Binary Tree ##


# Problem Link - 
https://leetcode.com/problems/minimum-depth-of-binary-tree/description/?envType=problem-list-v2&envId=tree

# Problem Statement -
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

Note: A leaf is a node with no children

# Query/ Code - 
*/
// TC -O(N)
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
    int minDepth(TreeNode* root) {
        if(root==NULL)
        {
            return 0;
        }
        int lh = minDepth(root->left);
        int rh = minDepth(root->right);
        if(lh==0 || rh ==0)
        {
            return 1+max(lh,rh);
        }
        return 1+min(lh, rh);
    }
};