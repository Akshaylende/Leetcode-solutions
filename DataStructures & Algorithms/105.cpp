/*
## 105. Construct Binary tree form Preorder and Inorder Traversal ##


# Problem Link - 
https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/?envType=study-plan-v2&envId=top-interview-150

# Problem Statement -
Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.


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
    int ind = 0;
    TreeNode* construct(vector<int>& preorder, int start, int end, vector<int>& inorder, unordered_map<int, int>& mp){
        if(start > end) return NULL;
        TreeNode *root = new TreeNode(preorder[ind]);
        ind++;
        root->left =  construct(preorder, start, mp[root->val]-1, inorder, mp);
        root->right = construct(preorder, mp[root->val]+1, end, inorder, mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        unordered_map<int, int> mp;
        for(int i=0; i<n; i++){
            mp[inorder[i]] = i;
        }
        return construct(preorder, 0, n-1, inorder, mp);
    }
};