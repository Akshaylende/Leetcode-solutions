/*
##  42. Trapping Rain Water ##


# Problem Link - 
https://leetcode.com/problems/trapping-rain-water/description/?envType=study-plan-v2&envId=top-interview-150

# Problem Statement -
Given n non-negative integers representing an elevation map where the width of each bar is 1, 
compute how much water it can trap after raining.

# Query/ Code - 
*/
// TC - O(N)
// SC - O(N)

class Solution {
public:
    int trap(vector<int>& height) {
        int N = height.size();
        vector<int> left(N), right(N);
        left[0] = height[0];
        for(int i=1; i<N; i++){
            left[i] = max(left[i-1], height[i]);
        }
        right[N-1] = height[N-1];
        for(int i=N-2; i>=0; i--){
            right[i] = max(right[i+1], height[i]);
        }
        int res = 0;
        for(int i=0; i<N; i++){
            res += (min(left[i], right[i])- height[i]);
        }
        return res;
    }
};

int main(){
    cout<<trap([0,1,0,2,1,0,1,3,2,1,2,1])<<endl; // 6
    return 0;
}