/*
## 106. Construct Binary tree from Inorder and Postorder Traversal ##


# Problem Link - 
https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/?envType=study-plan-v2&envId=top-interview-150

# Problem Statement -
Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.

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
    int ind;
    TreeNode* construct(vector<int>& inorder, int start, int end, vector<int>& postorder, unordered_map<int, int>& mp){
        if(start > end || ind < 0) return NULL;
        TreeNode *root = new TreeNode(postorder[ind]);
        ind--;
        root -> right = construct(inorder, mp[root->val]+1, end, postorder, mp);
        root -> left = construct(inorder, start, mp[root->val]-1, postorder, mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        unordered_map<int, int> mp;
        for(int i=0; i<n; i++){
            mp[inorder[i]] = i;
        }
        ind = n-1;
        return construct(inorder, 0, n-1, postorder, mp);
    }
};