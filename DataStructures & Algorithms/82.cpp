/*
## 82. Remove Duplicates from sorted List II ##


# Problem Link - 
https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/description/?envType=study-plan-v2&envId=top-interview-150

# Problem Statement -
Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.

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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return head;
        ListNode *newHead = new ListNode(-101);
        ListNode *curr = newHead, *ptr = head;
        while(ptr){
            int count = 0;
            while(ptr->next && ptr->val == ptr->next->val){
                count++;
                ptr = ptr->next;
            }
            if(count == 0) {
                curr->next = ptr;
                curr = ptr;
            }
            else if(!ptr->next){
                curr-> next = NULL;
            }
            ptr = ptr -> next;
        }
        return newHead->next;
    }
};