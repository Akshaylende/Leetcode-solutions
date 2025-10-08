/*
## 199. Binary Tree Right side view ##


# Problem Link - 
https://leetcode.com/problems/binary-tree-right-side-view/?envType=study-plan-v2&envId=top-interview-150

# Problem Statement -
Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        queue<TreeNode *> q;
        if(root){
            q.push(root);
            q.push(NULL);
        }
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            if(!node){
                if(!q.empty()) q.push(NULL);
                continue;
            }
            if(!q.front()){
                res.push_back(node->val);
            }
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);

        }
        return res;
    }
};