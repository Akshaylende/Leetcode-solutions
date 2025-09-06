/*
## 169. Majority Element ##


# Problem Link - 
https://leetcode.com/problems/majority-element/description/?envType=study-plan-v2&envId=top-interview-150

# Problem Statement -
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

# Query/ Code - 
*/
/*
Intuition is to find the element that appears more than N/2 times. 
Approach  -  Using Two Pointers or two variable 
Step 1 - Initialize two variables, one for freq count and the other for storing variable 
step 2 - Iterate through the array 
step 3 - check if the freq of a majority element is 0 then change the majority element to current element
step 4 - check if the majority ele is equal current element then increase the freq. count else decrease it.
step 5 - return the majority value as it stored the value.
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majority = 0, freq = 0;
        for(auto x : nums){
            if(freq == 0) majority = x;
            if(majority == x) freq++;
            else freq--;
        }
        return majority;
    }
};

int main(){
    cout<<majorityElement([3,2,3])<<endl;
    return 0;
}


// TC - O(N)
// SC - O(1)