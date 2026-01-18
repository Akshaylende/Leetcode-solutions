/*
## 352. DataStream as Disjoint Intervals ##


# Problem Link - 
https://leetcode.com/problems/data-stream-as-disjoint-intervals/description/

# Problem Statement -
Given a data stream input of non-negative integers a1, a2, ..., an, summarize the numbers seen so far as a list of disjoint intervals.

Implement the SummaryRanges class:

SummaryRanges() Initializes the object with an empty stream.
void addNum(int value) Adds the integer value to the stream.
int[][] getIntervals() Returns a summary of the integers in the stream currently as a list of disjoint intervals [starti, endi]. The answer should be sorted by starti.

# Query/ Code - 
*/

// TC - O(N log N)
// SC - O(N)


class SummaryRanges {
    vector<vector<int>> intervals;
    unordered_set<int> duplicate;
public:
    SummaryRanges() {

    }
    
    void addNum(int value) {
        if(duplicate.find(value) != duplicate.end()) return;
        intervals.push_back({value, value});
        duplicate.insert(value);
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> summary;
        sort(intervals.begin(), intervals.end());
        if(intervals.size() == 0) return intervals;
        int start = intervals[0][0], end = intervals[0][1];
        for(int i=1; i<intervals.size(); i++){
            if(intervals[i][0]-intervals[i-1][1] == 1){
                end = intervals[i][1];
            }
            else{
                summary.push_back({start, end});
                start = intervals[i][0];
                 end = intervals[i][1];
            }
        }
        summary.push_back({start, end});
        return summary;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */