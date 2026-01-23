/*
## 2080. Range Frequencies Queries ##


# Problem Link - 
https://leetcode.com/problems/range-frequency-queries/description/

# Problem Statement -
Design a data structure to find the frequency of a given value in a given subarray.

The frequency of a value in a subarray is the number of occurrences of that value in the subarray.

Implement the RangeFreqQuery class:

RangeFreqQuery(int[] arr) Constructs an instance of the class with the given 0-indexed integer array arr.
int query(int left, int right, int value) Returns the frequency of value in the subarray arr[left...right].
A subarray is a contiguous sequence of elements within an array. arr[left...right] denotes the subarray that contains the elements of nums between indices left and right (inclusive).

# Query/ Code - 
*/

// TC - O(log N)
// SC - O(N)

class RangeFreqQuery {
    unordered_map<int, vector<int>> freq;
public:
    RangeFreqQuery(vector<int>& arr) {
        for(int i=0; i<arr.size(); i++){
            freq[arr[i]].push_back(i);
        }
    }
    
    int query(int left, int right, int value) {
        int low = lower_bound(freq[value].begin(), freq[value].end(), left) - freq[value].begin();
        int high = upper_bound(freq[value].begin(), freq[value].end(), right) - freq[value].begin();
        return high - low;
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */