/*
## 215. Kth Largest Element in an array ##


# Problem Link - 
https://leetcode.com/problems/kth-largest-element-in-an-array/description/?envType=study-plan-v2&envId=top-interview-150

# Problem Statement -
Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

Can you solve it without sorting?

# Query/ Code - 
*/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(auto x : nums){
            pq.push(x);
        }
        while(--k)pq.pop();
        return pq.top();
    }
};