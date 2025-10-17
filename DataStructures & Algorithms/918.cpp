/*
## 918. Maximum Sum Circular Subarray ##


# Problem Link - 
https://leetcode.com/problems/maximum-sum-circular-subarray/?envType=study-plan-v2&envId=top-interview-150

# Problem Statement -
Given a circular integer array nums of length n, return the maximum possible sum of a non-empty subarray of nums.

A circular array means the end of the array connects to the beginning of the array. Formally, the next element of nums[i] is nums[(i + 1) % n] and the previous element of nums[i] is nums[(i - 1 + n) % n].

A subarray may only include each element of the fixed buffer nums at most once. Formally, for a subarray nums[i], nums[i + 1], ..., nums[j], there does not exist i <= k1, k2 <= j with k1 % n == k2 % n.

# Query/ Code - 
*/

// TC - O(N)
// SC - O(N)

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        vector<int> suffix(n);
        suffix[n-1] = nums[n-1];
        int curr_sum = nums[n-1];
        for(int i= n-2; i>=0 ; i--){
            curr_sum += nums[i];
            suffix[i] = max(suffix[i+1], curr_sum);
        }
        int max_sum = INT_MIN;
        int special_sum = INT_MIN, prefix_sum = 0;
        curr_sum = 0;
        for(int i = 0; i<n; i++){
            curr_sum += nums[i];
            if(curr_sum > max_sum) max_sum = curr_sum;
            if(curr_sum < 0)  curr_sum =0;
            prefix_sum += nums[i];
            if(i+1 < n){
                special_sum = max(suffix[i+1]+prefix_sum, special_sum);
            }
        } 
        return max(special_sum, max_sum);
    }
};



