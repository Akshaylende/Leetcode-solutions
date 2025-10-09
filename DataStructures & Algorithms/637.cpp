/*
## 637. Average of levels in Binary Tree ##


# Problem Link - 
https://leetcode.com/problems/average-of-levels-in-binary-tree/description/?envType=study-plan-v2&envId=top-interview-150

# Problem Statement -
Given the root of a binary tree, return the average value of the nodes on each level in the form of an array. Answers within 10-5 of the actual answer will be accepted.

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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        queue<TreeNode *> q;
        if(root)
        {
           q.push(root);
           q.push(NULL);
        }
        double sum=0;
        int count=0;
        
        while(!q.empty())
        {
            TreeNode *temp=q.front();
            q.pop();
            if(!temp)
            {
                ans.push_back(sum/count);
                if(!q.empty())
                {
                    q.push(NULL);
                }
                
                count=0;
                sum=0;
                continue;
            }
            count++;
            sum+=temp->val;
            if(temp->left)
            {
                q.push(temp->left);
            }
            if(temp->right)
            {
                q.push(temp->right);
            }
            
        }
        return ans;
    }
};