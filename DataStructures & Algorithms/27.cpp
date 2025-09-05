/*
## 27. Remove Element ##


# Problem Link - 
https://leetcode.com/problems/remove-element/description/?envType=study-plan-v2&envId=top-interview-150

# Problem Statement -
Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The order of the elements may be changed. Then return the number of elements in nums which are not equal to val.

Consider the number of elements in nums which are not equal to val be k, to get accepted, you need to do the following things:

Change the array nums such that the first k elements of nums contain the elements which are not equal to val. The remaining elements of nums are not important as well as the size of nums.
Return k.

# Query/ Code - 
*/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i=0, j = nums.size()-1;
        int count = 0;
        while(i<=j){
            if(nums[j] == val){
                j--;
                continue;
            }
            if(nums[i] == val){
                swap(nums[i], nums[j]);
            }
            count++;
            i++;
        }
        return count;
    }
};

// Time Complexity = O(N)
// Space Complexity = O(1)


int main(){
    vector<int> nums([0,1,2,2,3,0,4,2]);
    Solution obj;
    cout<<obj.removeElement(nums, 2)<< endl;                // First K unique numbers
    return 0;
}


