/*
## 103. Binary Tree Zigzag level order Traversal ##


# Problem Link - 
https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/?envType=study-plan-v2&envId=top-interview-150

# Problem Statement -
Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).



# Query/ Code - 
*/
// Tc - O(N)
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
    vector<int> reverse1(vector<int>& nodes){
        int n = nodes.size();
        int i = 0, j = n-1;
        while(i<j){
            swap(nodes[i], nodes[j]);
            i++, j--;
        }
        return nodes;
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode *> que;
        vector<int> levels;
        if(root){
            que.push(root);
            que.push(NULL);
        }
        bool flag = false;
        while(!que.empty()){
            auto curr = que.front();
            que.pop();
            if(!curr){
                if(!que.empty()) que.push(NULL);
                if(flag) reverse1(levels);
                flag = !flag;
                res.push_back(levels);
                levels.clear();
                continue;
            }
            levels.push_back(curr->val);
            if(curr->left) que.push(curr->left);
            if(curr->right) que.push(curr->right);
        }
        return res;
    }
};