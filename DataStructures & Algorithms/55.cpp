/*
## 55. Jump Game ##


# Problem Link - 
https://leetcode.com/problems/jump-game/description/?envType=study-plan-v2&envId=top-interview-150

# Problem Statement -
You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.

# Query/ Code - 
*/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i = 1, steps = nums[0];
        while(i<nums.size()){
            if(steps<=0) break;
            steps = max(steps-1, nums[i]);
            i++;
        }
        return (i == nums.size())? true : false;
    }
};

int main(){
    canJump([3,2,1,0,4]);
    return 0;
}

// Time Complexity - O(N)
// Space Complexity - O(1)