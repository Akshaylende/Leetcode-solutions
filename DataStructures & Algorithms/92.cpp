/*
## 92. Reverse Linked List ll ##


# Problem Link - 
https://leetcode.com/problems/reverse-linked-list-ii/description/?envType=study-plan-v2&envId=top-interview-150

# Problem Statement -
Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.

 

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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *ptr = head;
        ListNode *dum = new ListNode(0);
        int count = 0;
        while(ptr){
            count+=1;
            if(count == left){
                ListNode *prev = NULL, *curr = ptr, *fast;
                while(curr && count <= right){
                    fast = curr->next;
                    curr->next = prev;
                    prev=curr;
                    curr = fast;
                    count++;
                }
                dum->next = prev;
                if(left == 1) head = prev;
                ptr -> next = curr;
            }
            dum = ptr;
            ptr = ptr->next;
        }
        return head;
    }
};