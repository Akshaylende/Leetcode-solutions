/*
## 15. 3Sum ##


# Problem Link - 
https://leetcode.com/problems/3sum/description/?envType=study-plan-v2&envId=top-interview-150

# Problem Statement -
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

# Query/ Code - 
*/
// Time complexity - O()
// Space complexity - O()

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int N = nums.size();
        sort(nums.begin(), nums.end());
        for(int i=0; i<N-2; i++){
            if(i==0 || nums[i]!= nums[i-1]){
                int j = i+1, k = N-1;
                while(j<k){
                    if(nums[i]+nums[j]+nums[k] == 0){
                        res.push_back({nums[i], nums[j], nums[k]});
                        while(j<k && nums[j] == nums[j+1])j++;
                        while(k>j && nums[k] == nums[k-1])k--;
                        j++, k--;
                    }
                    else if(nums[i]+nums[j]+nums[k]< 0) j++;
                    else k--;
                }
            }
        }
        return res;
    }
};
