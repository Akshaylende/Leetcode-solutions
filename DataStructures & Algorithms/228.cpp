/*
## 228. Summary Ranges ##


# Problem Link - 
https://leetcode.com/problems/summary-ranges/description/?envType=study-plan-v2&envId=top-interview-150

# Problem Statement -
You are given a sorted unique integer array nums.

A range [a,b] is the set of all integers from a to b (inclusive).

Return the smallest sorted list of ranges that cover all the numbers in the array exactly. That is, each element of nums is covered by exactly one of the ranges, and there is no integer x such that x is in one of the ranges but not in nums.

Each range [a,b] in the list should be output as:

"a->b" if a != b
"a" if a == b

# Query/ Code - 
*/

// TC - O(N)
// SC - O(1)

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if(nums.size()==0) return {};
        vector<string> res;
        int N = nums.size(), i=0;
        string range = to_string(nums[0]);
        for(int j = 1; j<N; j++){
            if(nums[j] == nums[j-1]+1){
                continue;
            }
            else{
                    if(j-i>1){
                    range = range + "->" +to_string(nums[j-1]);
            }
                res.push_back(range);
                range = to_string(nums[j]);
                i=j;
            }
        }
        if(i < N-1){
            range = range + "->" +to_string(nums[N-1]);
        }
        res.push_back(range);
        return res;
    }
};