/*
## 1287. Element appearing more than 25% In sorted array ##


# Problem Link - 
https://leetcode.com/problems/element-appearing-more-than-25-in-sorted-array/description/

# Problem Statement -
Given an integer array sorted in non-decreasing order, there is exactly one integer in the array that occurs more than 25% of the time, return that integer.

# Query/ Code - 
*/
// TC - O(N)
// SC - O(N)

class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> mp;
        for(auto x: arr){
            mp[x] +=1;
            if(mp[x] > n/4) return x;
        }
        return -1;
    }
};