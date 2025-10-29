/*
## 295. Find the median from Data Stream ##


# Problem Link - 
https://leetcode.com/problems/find-median-from-data-stream/description/?envType=study-plan-v2&envId=top-interview-150

# Problem Statement -
The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value, and the median is the mean of the two middle values.

For example, for arr = [2,3,4], the median is 3.
For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
Implement the MedianFinder class:

MedianFinder() initializes the MedianFinder object.
void addNum(int num) adds the integer num from the data stream to the data structure.
double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted.

# Query/ Code - 
*/
// TC - O(nlogn)
// SC - O(N)

class MedianFinder {
    priority_queue<int> lower, upper;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(lower.empty() || num <= lower.top()) lower.push(num);
        else upper.push(-1 * num);

        if(lower.size() > upper.size() + 1){
            upper.push(-1*lower.top());
            lower.pop();
        }
        else if(lower.size()<upper.size()){
            lower.push(-1*upper.top());
            upper.pop();
        }
    }
    
    double findMedian() {
        if(lower.size() == upper.size()) return (double) (lower.top() + (-1*upper.top()))/2;
        return lower.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */