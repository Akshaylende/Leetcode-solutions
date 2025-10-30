/*
## 373. Find K pairs with smallest sum ##


# Problem Link - 
https://leetcode.com/problems/find-k-pairs-with-smallest-sums/description/?envType=study-plan-v2&envId=top-interview-150

# Problem Statement -
You are given two integer arrays nums1 and nums2 sorted in non-decreasing order and an integer k.

Define a pair (u, v) which consists of one element from the first array and one element from the second array.

Return the k pairs (u1, v1), (u2, v2), ..., (uk, vk) with the smallest sums.

# Query/ Code - 
*/

// TC - O(N log N)
// SC - O(N*N)
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
        for(int i=0; i<nums1.size(); i++){
            pq.push({nums1[i]+nums2[0], 0});
        }
        vector<vector<int>> res;
        while(k--){
            auto [x, y] = pq.top();
            pq.pop();
            res.push_back({x-nums2[y], nums2[y]});
            if(y+1 < nums2.size()){
                pq.push({x-nums2[y]+ nums2[y+1], y+1});
            }
        }   
        return res;
    }
};