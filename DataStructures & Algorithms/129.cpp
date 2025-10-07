/*
## 129. Sum Root to Leaf Numbers ##


# Problem Link - 
https://leetcode.com/problems/sum-root-to-leaf-numbers/?envType=study-plan-v2&envId=top-interview-150

# Problem Statement -
You are given the root of a binary tree containing digits from 0 to 9 only.

Each root-to-leaf path in the tree represents a number.

For example, the root-to-leaf path 1 -> 2 -> 3 represents the number 123.
Return the total sum of all root-to-leaf numbers. Test cases are generated so that the answer will fit in a 32-bit integer.

A leaf node is a node with no children.

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
    int ans = 0;
    void get_sum(TreeNode *root, string value){
        if(!root) return;
        get_sum(root->left, value + to_string(root->val));
        get_sum(root->right, value + to_string(root->val));
        if(!root->left && !root->right){
            string temp = value + to_string(root->val);
            ans+= stoi(temp);
        }
    }
    int sumNumbers(TreeNode* root) {
        if(!root) return 0;
        get_sum(root, "");
        return ans;
    }
}; 