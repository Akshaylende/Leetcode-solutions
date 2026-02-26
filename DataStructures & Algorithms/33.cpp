/*
## 33. Search in Rotated Sorted array ##


# Problem Link - 
https://leetcode.com/problems/search-in-rotated-sorted-array/?envType=study-plan-v2&envId=top-interview-150

# Problem Statement -
There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly left rotated at an unknown index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be left rotated by 3 indices and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.

# Query/ Code - 
*/

// TC - O(log n)
// SC - O(1)

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n-1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(nums[mid] == target) return mid;
            if(nums[mid] >= nums[low]){
                if(nums[low]<= target && nums[mid] > target){
                    high = mid -1;
                }
                else{
                    low = mid + 1;
                }
            }
            if(nums[mid] < nums[high]){
                if(nums[mid] < target && nums[high]>= target){
                    low = mid +1;
                }
                else{
                    high = mid -1;
                }
            } 
        }
        return -1;
    }
};

// Approach - 
1. Initialize two pointers one at the start and the other at the end.
2. Iterate in a loop while low<=high, calculate mid
3. check if value at low <= mid then we have sorted array from low to mid right ? 
4. check for target value is in the search space boundary if it is then shrink the boundaries accordingly.
5. repeat for right hand side of the mid and shrink the boundaries.