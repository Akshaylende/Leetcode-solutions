/*
## 452. Minimum number of Arrows to burst balloons ##


# Problem Link - 
https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/description/?envType=study-plan-v2&envId=top-interview-150

# Problem Statement -
There are some spherical balloons taped onto a flat wall that represents the XY-plane. The balloons are represented as a 2D integer array points where points[i] = [xstart, xend] denotes a balloon whose horizontal diameter stretches between xstart and xend. You do not know the exact y-coordinates of the balloons.

Arrows can be shot up directly vertically (in the positive y-direction) from different points along the x-axis. A balloon with xstart and xend is burst by an arrow shot at x if xstart <= x <= xend. There is no limit to the number of arrows that can be shot. A shot arrow keeps traveling up infinitely, bursting any balloons in its path.

Given the array points, return the minimum number of arrows that must be shot to burst all balloons.

# Query/ Code - 
*/
// TC - O(N log N)
// SC - O(log N) -> as sorting takes logN space

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int N = points.size();
        int minArrow = 1;
        sort(points.begin(), points.end());
        auto overlapped = points[0];
        for(int i=1;i<N; i++){
            if(points[i][0] <= overlapped[1])
            {
                overlapped[0] = max(points[i][0], overlapped[0]);
                overlapped[1] = min(points[i][1], overlapped[1]);
            }
            else{
                minArrow++;
                overlapped = points[i];
            }
        }
        return minArrow;
    }
};