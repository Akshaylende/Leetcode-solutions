/*
## 80. Remove Duplicates from sorted Array II ##


# Problem Link - 
https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/description/?envType=study-plan-v2&envId=top-interview-150

# Problem Statement -
Given an integer array nums sorted in non-decreasing order, remove some duplicates in-place such that each unique element appears at most twice. The relative order of the elements should be kept the same.

Since it is impossible to change the length of the array in some languages, you must instead have the result be placed in the first part of the array nums. More formally, if there are k elements after removing the duplicates, then the first k elements of nums should hold the final result. It does not matter what you leave beyond the first k elements.

Return k after placing the final result in the first k slots of nums.

Do not allocate extra space for another array. You must do this by modifying the input array in-place with O(1) extra memory.

# Query/ Code - 
*/

/*
Intuition - using Two pointers 
Step 1 - put two pointers, one at index 1 and the iterative pointer j at index 2.
step 2 - Iterate the point by check nums[j] == nums[i-1] 
step 3 - looping in for umique element meanwhile swapping j = i+1 if there needs to change elements on the go in place
step 4 - Repeat these in combination with each other.
step 5 - return the final digit.
*/


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() < 3) return nums.size();
        int i = 1, j = 2;
        while(j < nums.size()){
            if(nums[j] == nums[i-1]){
                while(j<nums.size() && nums[j] == nums[i]) j++;
                if(j>=nums.size()) break;
                swap(nums[i+1], nums[j]);
            } 
            else{
                nums[i+1] = nums[j]; 
            };
            i++,j++;
        }
        return i+1;
    }
};

//  Time Complexity - O(N)
//  Space Complexity - O(1)