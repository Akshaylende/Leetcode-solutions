/*
## 21. Merge Two Sorted lists ##


# Problem Link - 
https://leetcode.com/problems/merge-two-sorted-lists/description/?envType=study-plan-v2&envId=top-interview-150

# Problem Statement -
You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

 

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1) return list2;
        if(!list2) return list1;
        ListNode *head = new ListNode(-1), *curr;
        curr = head;
        while(list1 && list2){
            if(list1->val < list2->val){
                curr->next = list1;
                list1 = list1->next;
            }
            else{
                curr->next =  list2;
                list2 = list2->next;
            }
            curr = curr->next;
        }
        if(list1){
            curr->next = list1;
        }
        if(list2){
            curr->next = list2;
        }
        return head -> next;
    }
};