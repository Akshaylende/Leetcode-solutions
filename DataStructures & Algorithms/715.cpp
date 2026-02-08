/*
## 715. Range Module ##


# Problem Link - 
https://leetcode.com/problems/range-module/description/

# Problem Statement -
A Range Module is a module that tracks ranges of numbers. Design a data structure to track the ranges represented as half-open intervals and query about them.

A half-open interval [left, right) denotes all the real numbers x where left <= x < right.

Implement the RangeModule class:

RangeModule() Initializes the object of the data structure.
void addRange(int left, int right) Adds the half-open interval [left, right), tracking every real number in that interval. Adding an interval that partially overlaps with currently tracked numbers should add any numbers in the interval [left, right) that are not already tracked.
boolean queryRange(int left, int right) Returns true if every real number in the interval [left, right) is currently being tracked, and false otherwise.
void removeRange(int left, int right) Stops tracking every real number currently being tracked in the half-open interval [left, right).

# Query/ Code - 
*/
// TC - O(N) 
// SC - O(N)

class RangeModule {
    struct Interval{
        int start, end;
        Interval(int start, int end){
            this->start = start;
            this->end = end;
        }
    };
    vector<Interval> range;
public:
    RangeModule() {
        
    }
    
    void addRange(int left, int right) {
        vector<Interval> intervals;
        int N = range.size();
        bool flag = false;
        for(int i=0; i<N; i++){
            auto interval = range[i];
            if(right < interval.start && !flag){
                intervals.push_back(Interval(left, right));
                flag = true;
            }
            if(right < interval.start || left > interval.end){
                intervals.push_back(interval);
            }
            else{
                left = min(left, interval.start);
                right = max(right, interval.end);
            }
        }
        if(!flag) intervals.push_back(Interval(left, right));
        range = intervals;
    }
    
    bool queryRange(int left, int right) {
       int l = 0, r = range.size() - 1;
       while(l <= r){
            int mid = l + (r-l)/2;
            if(range[mid].start >= right){
                r = mid - 1;
            }
            else if(range[mid].end <= left){
                l = mid + 1;
            }
            else{
                return range[mid].start <= left && range[mid].end >= right;
            }
       }
       return false;
    }
    
    void removeRange(int left, int right) {
       vector<Interval> intervals;
       int N = range.size();
       for(int i=0; i<N; i++){
            auto interval = range[i];
            if(right <= interval.start || left >= interval.end){
                intervals.push_back(interval);
            }
            else{
                if(left > interval.start){
                    intervals.push_back(Interval(interval.start, left));
                } 
                if(right < interval.end){
                    intervals.push_back(Interval(right, interval.end));
                }   
            }
       }
       range = intervals;
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */