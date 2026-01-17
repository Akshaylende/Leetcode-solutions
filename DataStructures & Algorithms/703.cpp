/*
## 703. Kth largest Element in a stream ##


# Problem Link - 
https://leetcode.com/problems/kth-largest-element-in-a-stream/

# Problem Statement -
You are part of a university admissions office and need to keep track of the kth highest test score from applicants in real-time. This helps to determine cut-off marks for interviews and admissions dynamically as new applicants submit their scores.

You are tasked to implement a class which, for a given integer k, maintains a stream of test scores and continuously returns the kth highest test score after a new score has been submitted. More specifically, we are looking for the kth highest score in the sorted list of all scores.

Implement the KthLargest class:

KthLargest(int k, int[] nums) Initializes the object with the integer k and the stream of test scores nums.
int add(int val) Adds a new test score val to the stream and returns the element representing the kth largest element in the pool of test scores so far.
 

# Query/ Code - 
*/

// TC - O(N log N)
// SC - O(N)


class KthLargest {
    int size;
    priority_queue<int, vector<int> , greater<int> > stream;
public:
    KthLargest(int k, vector<int>& nums) {
        this->size = k;
        for(auto x: nums){
            stream.push(x);
            if(stream.size() > size){
                stream.pop();
            }
        }
    }
    
    int add(int val) {
        stream.push(val);
        if(stream.size() > size)
            stream.pop();
        return stream.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */