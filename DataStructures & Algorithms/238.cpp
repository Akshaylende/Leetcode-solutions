/*
## 238. Product of Array Except self ##


# Problem Link - 
https://leetcode.com/problems/product-of-array-except-self/?envType=study-plan-v2&envId=top-interview-150

# Problem Statement -
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.


# Query/ Code - 
*/
// TC - O(1)
// SC - O(1)

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size=nums.size();
        vector<int> res(size, 1);
        int temp=1;
        for(int i=0;i<size;i++)
        {
            res[i]=temp;
            temp*=nums[i];
        }
        temp=1;
        for(int i=size-1;i>=0;i--)
        {
            res[i]*=temp;
            temp*=nums[i];
        }
        return res;
    }
};

int main(){
    vector<int> nums(productExceptSelf([1,2,3,4]));
    for(auto x:nums){
        cout<<x<< " ";
    }
    cout<<endl;
    return 0;
}