/*
## 57. Insert Interval ##


# Problem Link - 
https://leetcode.com/problems/insert-interval/description/?envType=study-plan-v2&envId=top-interview-150

# Problem Statement -
You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith interval and intervals is sorted in ascending order by starti. You are also given an interval newInterval = [start, end] that represents the start and end of another interval.

Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).

Return intervals after the insertion.

Note that you don't need to modify intervals in-place. You can make a new array and return it.

# Query/ Code - 
*/
// SC - O(N)
// TC - O(2N)
Class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> nintervals;
        int N = intervals.size();
        bool flag = true;
        for(int i=0;i<N;i++){
            if(intervals[i][0]>newInterval[0] && flag){
                nintervals.push_back(newInterval);
                flag = false;
            }
            nintervals.push_back(intervals[i]);
        }
        if(flag) nintervals.push_back(newInterval);
        intervals = nintervals;
        nintervals.erase(nintervals.begin(), nintervals.end());
        auto overlap = intervals[0];
        for(int i=1; i<N+1; i++){
            if(overlap[1]>=intervals[i][0]){
                overlap[1] = max(intervals[i][1], overlap[1]);
            }
            else{
                nintervals.push_back(overlap);
                overlap = intervals[i];
            }
        }
        nintervals.push_back(overlap);
        return nintervals;
    }
};


// # Approach 2 
// Checking if newInterval is smaller than current Interval
// checking at each interval of intervals if it has overlapping with newInterval, if it has so extending boundaries of newInterval or moving on
// Checking if newInterval is greater than current Interval

// SC - O(N)
// TC - O(N)
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> newintervals;
        int N = intervals.size();
        if(N == 0) return {newInterval};
        bool flag = true;
        for(int i=0; i<N; i++){
            auto Interval = intervals[i];
            if(newInterval[1] < Interval[0] && flag) {
                newintervals.push_back(newInterval);
                flag = false;
            }
            if(Interval[0] > newInterval[1] || Interval[1] < newInterval[0]){
                newintervals.push_back(Interval);
            }
            else{
                newInterval[0] = min(newInterval[0], Interval[0]);
                newInterval[1] = max(newInterval[1], Interval[1]);
            }
        }
        if(flag) newintervals.push_back(newInterval);
        return newintervals;
    }
};