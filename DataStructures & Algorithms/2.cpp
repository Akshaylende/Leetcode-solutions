/*
## 2. Add Two Number ##


# Problem Link - 
https://leetcode.com/problems/add-two-numbers/description/?envType=study-plan-v2&envId=top-interview-150

# Problem Statement -
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

# Query/ Code - 
*/

// TC - O(max(M, N))
// SC - O(max(M, N))+1

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode(-1);
        ListNode *curr = head; 
        int carry = 0;
        while(l1 && l2){
            int value = l1->val + l2->val + carry;
            carry = 0;
            if(value > 9){
                carry = value / 10;
                value  = value % 10;
            }
            curr->next = new ListNode(value);
            curr = curr->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1){
            int value = l1->val+carry;
            carry = 0;
            if(value>9){
                carry = value / 10;
                value  = value % 10;
            }
            curr->next = new ListNode(value);
            curr = curr -> next;
            l1 = l1 -> next;
        }
        while(l2){
            int value = l2->val+carry;
            carry = 0;
            if(value>9){
                carry = value / 10;
                value  = value % 10;
            }
            curr->next = new ListNode(value);
            curr = curr -> next;
            l2 = l2 -> next;
        }
        if(carry){
            curr -> next = new ListNode(carry);
            curr = curr-> next;
        }
        return head->next;
    }
};