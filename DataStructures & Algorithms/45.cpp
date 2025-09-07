/*
## 45. Jump Game II ##


# Problem Link - 
https://leetcode.com/problems/jump-game-ii/?envType=study-plan-v2&envId=top-interview-150

# Problem Statement -
You are given a 0-indexed array of integers nums of length n. You are initially positioned at index 0.

Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at index i, you can jump to any index (i + j) where:

0 <= j <= nums[i] and
i + j < n
Return the minimum number of jumps to reach index n - 1. The test cases are generated such that you can reach index n - 1.

# Query/ Code - 
*/
// TC - O(N)
// SC - O(1)


/*
Approach - using Modified two pointers 
step 1 - Initialize two variables currReach and currMax to track the indexes of reach in the given array
step 2 - Initialize a jump variable to keep a track of number of jumps.
step 3 - check at any index if i + nums[i] is greater than maximum current reach if it is then update the maxReach 
step 4 - check if (i == currReach) then update the currReach to currMax reach and increment the jumps counter
step 5 - return the jumps count.
*/



class Solution{
public:
    int jump(vector<int>& nums){
        int N = nums.size();
        int i=0, jumps = 0;
        int currReach = 0, currMax = 0;
        while(i<N){
            if(i+nums[i] > currMax){
                currMax = i+nums[i];
            }
            if(currReach == i && i != N-1){
                currReach = currMax;
                jumps++;
            }
            i++;
        }
        return jumps;
    }
};

// Main method for calling
int main(){
    cout<< jump([2,3,1,1,4])<<endl;
    return 0;
}