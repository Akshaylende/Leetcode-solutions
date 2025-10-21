/*
## 23. Merge K sorted Lists ##


# Problem Link - 
https://leetcode.com/problems/merge-k-sorted-lists/description/?envType=study-plan-v2&envId=top-interview-150

# Problem Statement -
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.


# Query/ Code - 
*/

// TC - O(n log n)
// SC - O(N)
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>> > pq;
        for(auto head : lists){
            if(head) pq.push({head->val, head});
        }
        ListNode *newHead = NULL, *curr = new ListNode(-1);
        while(!pq.empty()){
            auto [val, node] = pq.top();
            pq.pop();
            curr->next = node;
            curr = node;
            if(!newHead) newHead = curr;
            node = node -> next;
            if(node) pq.push({node->val, node});
        }
        return newHead;
    }
}; 



