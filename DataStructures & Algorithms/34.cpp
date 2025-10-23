/*
## 34. Find the first and the last occcurence of the Element in sorted Array ##


# Problem Link - 
https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/?envType=study-plan-v2&envId=top-interview-150

# Problem Statement -
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

# Query/ Code - 
*/
// Tc - O(log n)
// SC - O(1)

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = -1, second = -1;
        int n = nums.size();
        int low = 0, high = n-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(nums[mid] == target){
                first = mid;
            }
            if(nums[mid] >= target){
                high = mid -1 ;
            }
            if(nums[mid] < target){
                low = mid +1;
            }
        }
        low = 0;
        high = n-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(nums[mid] == target){
                second = mid;
            }
            if(nums[mid] > target){
                high = mid -1 ;
            }
            if(nums[mid] <= target){
                low = mid +1;
            }
        }
        return {first, second};
    }
};