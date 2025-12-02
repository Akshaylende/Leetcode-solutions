/*
## 532. K-diff Pairs in an Array ##


# Problem Link - 
https://leetcode.com/problems/k-diff-pairs-in-an-array/description/?envType=problem-list-v2&envId=binary-search

# Problem Statement -
Given an array of integers nums and an integer k, return the number of unique k-diff pairs in the array.

A k-diff pair is an integer pair (nums[i], nums[j]), where the following are true:

0 <= i, j < nums.length
i != j
|nums[i] - nums[j]| == k
Notice that |val| denotes the absolute value of val.




# Query/ Code - 
*/
// TC - O(N)
// SC - O(N)
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(auto x:nums){
            mp[x]+=1;
        }
        int pairs = 0;
        if(k==0){
            for(auto [x,y]:mp) if(y>1) pairs++;
            return pairs;
        } 
        for(auto [x,y] : mp){
            if(mp.find(x+k) != mp.end()){
                pairs++;
            }
        }
        return pairs;
    }
};