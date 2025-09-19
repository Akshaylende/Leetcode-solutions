/*
## 128. Longest Consecutive sequence ##


# Problem Link - 
https://leetcode.com/problems/longest-consecutive-sequence/description/?envType=study-plan-v2&envId=top-interview-150

# Problem Statement -
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

# Query/ Code - 
*/
//TC - O(N log N)
//SC - O(1)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        int res = 1, cnt=1;
        sort(nums.begin(), nums.end());
        for(int i=1; i<nums.size(); i++){
            if(nums[i-1]+1==nums[i]){
                cnt++;
                res = max(res, cnt);
            }
            else if(nums[i-1] != nums[i]) cnt = 1; 
        }
        return res;
    }
};

//Optimized for Time complexity
// TC - O(N)
// SC - O(N)

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int res = 0;
        unordered_set<int> st(nums.begin(), nums.end());
        for(auto x: st){
            if(st.find(x-1)==st.end()){
                int length = 0;
                while(st.find(length+x)!=st.end()){
                    length++;
                }
                res = max(res, length);
            }
        }
        return res;
    }
};