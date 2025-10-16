/*
## 35. Search Insert Position ##


# Problem Link - 
https://leetcode.com/problems/search-insert-position/?envType=study-plan-v2&envId=top-interview-150

# Problem Statement -
Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.

# Query/ Code - 
*/
// TC - O(logn)
// SC - O(1)

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low=0;
        int high=nums.size()-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(nums[mid]>target)
            {
                high=mid-1;
            }
            else if(nums[mid]<target)
            {
                low=mid+1;
            }
            else
            {
                return mid;
            }
        }
        return low;
    }
};