/*
## 109. Convert Sorted List to Binary Search Tree ##


# Problem Link - 
https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/description/?envType=problem-list-v2&envId=tree

# Problem Statement -
Given the head of a singly linked list where elements are sorted in ascending order,
convert it to a height-balanced binary search tree.

# Query/ Code - 
*/

// TC - O(N)
// SC - 

class Solution {
public:
    ListNode* getmiddle(ListNode* head)
    {
        ListNode *slow=head, *fast=head;
        ListNode *prev=NULL;
        while(fast && fast->next)
        {
            prev=slow;
            slow=slow->next;
            
            fast=fast->next->next;
        }
        if(prev!=NULL)
        {
            prev->next=NULL;
        }
        return slow;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head)
        {
            return NULL;
        }
        if(!head->next)
        {
            return new TreeNode(head->val);
        }
        ListNode* middle = getmiddle(head);
        TreeNode* root = new TreeNode(middle->val);
        root->right = sortedListToBST(middle->next);
        middle->next = NULL;
        root->left = sortedListToBST(head);
        return root;
    }
};