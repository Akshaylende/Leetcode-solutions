/*
## 25. Reverse Nodes in k-Group ##


# Problem Link - 
https://leetcode.com/problems/reverse-nodes-in-k-group/description/?envType=study-plan-v2&envId=top-interview-150


# Problem Statement -
Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.


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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *newHead = new ListNode(-1, head), *ptr = head;
        int n = 0, count = 0;
        while(ptr){
            n++;
            ptr = ptr -> next;
        }
        ptr = newHead;
        while(count+k <= n){
            ListNode *prev = NULL, *curr = ptr->next, *temp, *first = ptr->next;
            int i =0;
            while(i<k){
                i++;
                temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }  
            if(newHead->val == -1) newHead = prev;
            ptr -> next = prev;
            ptr = first;
            ptr -> next = curr;
            count +=k;
        }
        return newHead;
    }
};