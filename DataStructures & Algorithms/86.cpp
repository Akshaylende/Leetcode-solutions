/*
## 86. Partition List ##


# Problem Link - 
https://leetcode.com/problems/partition-list/description/?envType=study-plan-v2&envId=top-interview-150

# Problem Statement -
Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

# Query/ Code - 
*/
// TC - O(N)
// SC - O(1)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(!head) return head;
        ListNode *small = new ListNode(-101), *large = new ListNode(-101);
        ListNode *ptr = head, *newhead = large;
        head = small;                
        while(ptr){
            if(ptr->val < x){
                small -> next = ptr;
                small = ptr;
            }
            else{
                large -> next = ptr;
                large = ptr;
            }
            ptr = ptr -> next;
        }
        large->next = NULL;
        small -> next = newhead->next;
        return head -> next;
    }
};