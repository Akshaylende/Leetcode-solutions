/*
## 189. Rotate Array ##


# Problem Link - 
https://leetcode.com/problems/rotate-array/description/?envType=study-plan-v2&envId=top-interview-150

# Problem Statement -
Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.


# Query/ Code - 
*/
/*
Approach - using reversing Algorithm 
step 1 - check if k > N  i.e size of an array so no point of rotating it more than the original size itself
step 2 - so modulo or remainder thing will work
step 3 - reverse the array in O(N)
step 4 - use k as a pivot and reverse before k and then including k till the end of array
*/


class Solution {
public:
    vector<int> reverse1(vector<int>& nums, int left, int right){
        while(left<right){
            swap(nums[left], nums[right]);
            left++, right--;
        }
        return nums;
    }
    void rotate(vector<int>& nums, int k) {
        int N = nums.size();
        k = k % N;
        reverse1(nums, 0, N-1);
        reverse1(nums, 0, k-1);
        reverse1(nums, k, N-1);
    }
};

int main(){
    rotate([1,2,3,4,5,6,7], 3);
    // nums = [5,6,7,1,2,3,4]
    return 0;
}