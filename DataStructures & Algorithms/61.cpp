/*
## 61. Rotate List ##


# Problem Link - 
https://leetcode.com/problems/rotate-list/description/?envType=study-plan-v2&envId=top-interview-150

# Problem Statement -
Given the head of a linked list, rotate the list to the right by k places.


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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode *ptr = head;
        if(!head) return head;
        int count = 0;
        while(ptr){
            count++;
            ptr = ptr -> next;
        }
        ptr = head;
        k = k % count;
        if(k == 0) return head;
        while(count-1 > k && ptr){
            ptr = ptr -> next;
            count--;
        }
        ListNode *newHead = ptr->next, *temp;
        ptr -> next = NULL;
        temp = newHead;
        while(temp && temp->next){
            temp = temp -> next;
        }
        temp -> next = head;
        return newHead;
    }
};