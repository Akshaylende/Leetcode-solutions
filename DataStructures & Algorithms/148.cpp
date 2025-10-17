/*
## 148. sort List ##


# Problem Link - 
https://leetcode.com/problems/sort-list/?envType=study-plan-v2&envId=top-interview-150

# Problem Statement -
Given the head of a linked list, return the list after sorting it in ascending order.



# Query/ Code - 
*/
// TC - O(n log n)
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
    ListNode* getMid(ListNode* head){
        if(!head) return head;
        ListNode *slow = head, *fast = head->next;
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    ListNode* merge(ListNode* l1, ListNode* l2){
        if(!l1) return l2;
        if(!l2) return l1;
        ListNode *head, *curr = new ListNode(-1);
        if(l1->val <= l2->val) head = l1;
        else head = l2;
        while(l1 && l2){
            if(l1->val <= l2->val){
                curr->next = l1;
                curr = l1;
                l1 = l1->next;
            }
            else{
                curr->next = l2;
                curr = l2;
                l2 = l2->next;
            }
        }
        while(l1){
            curr->next = l1;
            curr = l1;
            l1 = l1->next;
        }
        while(l2){
            curr->next = l2;
            curr = l2;
            l2 = l2->next;    
        }
        return head;
    }
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *left = head;
        ListNode *right = getMid(head);
        ListNode *temp = right ->next;
        right->next = NULL;
        right = temp;
        left = sortList(left);
        right = sortList(right);
        return merge(left, right);
    }
};