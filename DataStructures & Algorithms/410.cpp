/*
## 410. Split Array Largest Sum ##


# Problem Link - 
https://leetcode.com/problems/split-array-largest-sum/description/?envType=problem-list-v2&envId=binary-search

# Problem Statement -
Given an integer array nums and an integer k, split nums into k non-empty subarrays such that the largest sum of any subarray is minimized.

Return the minimized largest sum of the split.

A subarray is a contiguous part of the array.

# Query/ Code - 
*/

TC - O(nlogn)
SC - O(1)

class Solution {
public:
    int check(vector<int>& nums, int k, int alloc){
        int max_sum = 0, sum = 0, cnt=0;
        for(auto x: nums){
            if(sum+x > alloc){
                cnt++;
                max_sum = max(max_sum, sum);
                sum = 0;
            }
            sum += x;
            
        } 
        max_sum = max(max_sum, sum);
        if(cnt>=k || sum > alloc) return -1;
        return max_sum;
    }
    int splitArray(vector<int>& nums, int k) {
        int res = INT_MAX;
        int low = 0, high = 0;
        for(auto x:nums){
            low = max(low, x);
            high +=x;
        }
        // cout<< low<<" "<< high <<endl;
        while(low<=high){
            int mid = low+(high-low)/2;
            // cout<<"mid "<< mid<<" ";
            int temp = check(nums, k, mid);
            if(temp == -1){
                low = mid+1;
            }
            else{
                // cout<<temp<<" ";
                res = min(temp, res);
                high = mid-1;
            }
        }
        return res;
    }
};