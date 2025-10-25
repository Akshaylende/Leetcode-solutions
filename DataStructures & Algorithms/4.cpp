/*
## 4. Median of two sorted arrays ##


# Problem Link - 
https://leetcode.com/problems/median-of-two-sorted-arrays/description/?envType=study-plan-v2&envId=top-interview-150

# Problem Statement -
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

# Query/ Code - 
*/
// TC - O(N+M)
// SC - O(N+M)

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>nums;
        int n1 = nums1.size(), n2 = nums2.size();
        int i = 0, j = 0;
        while(i<n1 && j<n2){
            if(nums1[i]<=nums2[j]){
                nums.push_back(nums1[i]);
                i++;
            }
            else{
                nums.push_back(nums2[j]);
                j++;
            }
        }
        while(i<n1){
            nums.push_back(nums1[i]);
            i++;
        }
        while(j<n2){
            nums.push_back(nums2[j]);
            j++;
        }
        int n =nums.size();
        if(n%2 == 0){
            return (nums[(n/2)-1] + nums[n/2])/2.00000;
        }
        return nums[(n/2)];
    }
};


