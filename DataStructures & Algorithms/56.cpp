/*
## 56. Merge Intervals ##


# Problem Link - 
https://leetcode.com/problems/merge-intervals/description/?envType=study-plan-v2&envId=top-interview-150

# Problem Statement -
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and 
return an array of the non-overlapping intervals that cover all the intervals in the input.
 

# Query/ Code - 
*/

// TC - O(N log N)
// SC - O(2) 
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int N = intervals.size();
        // if(N == 1) return intervals;
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> overlaps;
        vector<int> interval(intervals[0]);
        for(int i=1;i<N;i++){
            if(intervals[i][0]<=interval[1]){
                interval[1] =  max(interval[1], intervals[i][1]);
            }
            else{
                overlaps.push_back(interval);
                interval[0] = intervals[i][0];
                interval[1] = intervals[i][1];
            }
        }
        overlaps.push_back(interval);
        return overlaps;
    }
};