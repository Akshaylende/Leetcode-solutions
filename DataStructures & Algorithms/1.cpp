/*
## 1. Two Sum ##


# Problem Link - 
https://leetcode.com/problems/two-sum/description/?envType=study-plan-v2&envId=top-interview-150

# Problem Statement -
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

# Query/ Code - 
*/
// TC - O(N)
// SC - O(N)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        for(int i=0;i<nums.size();i++){
            if(mp.find(target-nums[i]) != mp.end()){
                return {mp[target-nums[i]], i};
            }
            mp[nums[i]] = i;
        }
        return {-1};
    }
};