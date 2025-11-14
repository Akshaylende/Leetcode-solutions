/*
## 69. Sqrt(x) ##


# Problem Link - 
https://leetcode.com/problems/sqrtx/description/?envType=study-plan-v2&envId=top-interview-150

# Problem Statement -
Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.

You must not use any built-in exponent function or operator.

For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.

# Query/ Code - 
*/
// Tc - O(log x)
// Sc - O(1)

class Solution {
public:
    int mySqrt(int x) {
        int low = 1, high = x;
        int res = 0;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(mid <= x/mid){
                res = mid;
                low = mid + 1;
            }
            else{
                high = mid -1;
            }
        }
        return res;
    }
};