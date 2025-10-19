/*
## 162. Find Peak Element ##


# Problem Link - 
https://leetcode.com/problems/find-peak-element/description/?envType=study-plan-v2&envId=top-interview-150

# Problem Statement -
A peak element is an element that is strictly greater than its neighbors.

Given a 0-indexed integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.

You may imagine that nums[-1] = nums[n] = -∞. In other words, an element is always considered to be strictly greater than a neighbor that is outside the array.

You must write an algorithm that runs in O(log n) time.

# Query/ Code - 
*/
// TC - O(log N)
// SC - O(1)

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n-1;
        while(low < high){
            int mid = low + (high - low)/2;     
            if(nums[mid] > nums[mid+1]){
                high = mid;
            }
            else low = mid + 1;
        }
        return low;
    }
};