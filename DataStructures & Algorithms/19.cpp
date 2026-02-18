/*
## 19. Remove Nth node from End of List ##


# Problem Link - 
https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/?envType=study-plan-v2&envId=top-interview-150

# Problem Statement -
Given the head of a linked list, remove the nth node from the end of the list and return its head.


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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *end = head;
        int count = 0;
        while(count < n){
            count++;
            end = end -> next;
        }
        if(!end) head = head ->next;
        ListNode *ptr = head;
        while(end && ptr){
            if(!end->next){
                ptr->next = ptr->next->next;
            }
            end = end->next;
            ptr = ptr->next;
        }
        return head;
    }
};

#Approach - 
1. iterate till N from head 
2. 