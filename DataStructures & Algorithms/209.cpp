/*
## 209. Minimum size subarray sum ##


# Problem Link - 
https://leetcode.com/problems/minimum-size-subarray-sum/description/?envType=study-plan-v2&envId=top-interview-150

# Problem Statement -
Given an array of positive integers nums and a positive integer target, return the minimal length of a subarray whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.


# Query/ Code - 
*/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int size= nums.size();
        int maxl=INT_MAX, sum=0;
        int i=0, j=0;
        for(j=0;j<size;j++)
        {
            sum+=nums[j];
            while(sum>=target)
            {      
                maxl=min(maxl, j-i+1);
                sum-=nums[i];
                i++;
            }
        }
        return maxl==INT_MAX ? 0 : maxl; 
    }
};