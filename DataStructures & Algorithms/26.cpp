/*
## 26. Remove Duplicates from Sorted Array ##


# Problem Link - 
https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/?envType=study-plan-v2&envId=top-interview-150

# Problem Statement -
Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same. Then return the number of unique elements in nums.

Consider the number of unique elements of nums to be k, to get accepted, you need to do the following things:

Change the array nums such that the first k elements of nums contain the unique elements in the order they were present in nums initially. The remaining elements of nums are not important as well as the size of nums.
Return k.

# Query/ Code - 
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<2) return 1;
        int i=0, j=i+1;
        while(j<nums.size()){
            if(nums[j] > nums[i]){
                swap(nums[j], nums[i+1]);
                i=i+1;
            }
            j++;
        }
        return i+1;
    }
};

// Time Complexity = O(N)
// Space Complexity = O(1)
/*
used Two pointers Approach to solve the problem 
Step 1 - Putting i=0 , j =i+1 intially
Step 2 - comparing if the jth index number is unique or not with ith index number
Step 3 - If it is then swap it with ith index number.
Step 4 - Repeat this until j reaches to the end of the nums array 
Step 5 -return the of first unique occurrences using i+1 as 0 can be index and not size
*/
