/*
## 11. Container with Most Water ##


# Problem Link - 
https://leetcode.com/problems/container-with-most-water/description/?envType=study-plan-v2&envId=top-interview-150

# Problem Statement -
You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.

# Query/ Code - 
*/

 TC - O(N)
 SC - O(1)

class Solution {
public:
    int maxArea(vector<int>& height) {
        int N = height.size();
        int i=0, j = N-1;
        int maxarea = INT_MIN;
        while(i<j){
            int width = j-i;
            int heights = min(height[i], height[j]);
            maxarea = max(maxarea, heights * width);
            if(height[i]<height[j]) i++;
            else j--;
        } 
        return maxarea; 
    }
}


// Explanation

1. Initialize two pointers one at the start and the other at the end. 
2. start iterating the array and calculating maximum area by width * min height of the two pointer
3. move the pointer from the shorter element till i<j 
