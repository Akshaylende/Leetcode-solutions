/*
## 220. Contains Duplicate III ##


# Problem Link - 
https://leetcode.com/problems/contains-duplicate-iii/description/?envType=problem-list-v2&envId=sliding-window

# Problem Statement -
You are given an integer array nums and two integers indexDiff and valueDiff.

Find a pair of indices (i, j) such that:

i != j,
abs(i - j) <= indexDiff.
abs(nums[i] - nums[j]) <= valueDiff, and
Return true if such pair exists or false otherwise.

# Query/ Code - 
*/
// TC -  o(Nlogn)
// SC - O(N)
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        int n = nums.size();
        set<int> nearby;
        for(int i=0, j=0;j<n; j++){
            if(j>indexDiff) nearby.erase(nums[i++]);
            //   |x-nums[j]| <= valueDiff
            //   -valueDiff >= x-nums[j] <= valueDiff
            //    x-nums[j] >= -valueDiff
            //    x >= nums[j] - valueDiff
            auto it = nearby.lower_bound(nums[j]-valueDiff);
            // cout<<*it<<endl;
            //getting a pointer 
            if(it != nearby.end() && *it-nums[j] <= valueDiff) return true;
            nearby.insert(nums[j]);
        }
        return false;
    }
};