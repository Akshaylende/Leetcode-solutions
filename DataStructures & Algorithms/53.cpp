/*
## 53. Maximum Subarray sum ##


# Problem Link - 
https://leetcode.com/problems/maximum-subarray/?envType=study-plan-v2&envId=top-interview-150

# Problem Statement -
Given an integer array nums, find the subarray with the largest sum, and return its sum.

# Query/ Code - 
*/

// TC - O(N)
// SC - O(1)

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr=0;
        int maxt=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            curr+=nums[i];
            if(curr>maxt)
            {
                maxt=max(maxt,curr);
            }
            if(curr<0)
            {
                curr=0;
            }
        }
        return maxt;
    }
};



//Approach - 
1. Initialize max_till_now and curr sum variable. 
2. Iterate for loop on a variable and apply kadane algorithm