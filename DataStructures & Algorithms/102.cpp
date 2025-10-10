/*
## 102. Binary Tree level order Traversal ##


# Problem Link - 
https://leetcode.com/problems/binary-tree-level-order-traversal/description/?envType=study-plan-v2&envId=top-interview-150

# Problem Statement -
Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).



# Query/ Code - 
*/
//TC - O(N)
//SC - O(N)

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        queue<TreeNode *>q;
        if(root)
        {
            q.push(root);
            q.push(NULL);
        }
        TreeNode *temp;
        vector<int>k;
        while(!q.empty())
        {
            temp=q.front();
            q.pop();
            if(temp==NULL)
            {
                if(!q.empty())
                {
                    q.push(NULL);
                }
                ans.push_back(k);
                k.clear();
            }
            else{
                k.push_back(temp->val);
                if(temp->left)
                {
                    q.push(temp->left);
                }
                if(temp->right)
                {
                    q.push(temp->right);
                }
            }
            
        }
        return ans;
    }
};