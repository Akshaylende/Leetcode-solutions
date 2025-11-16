/*
## 172. Factorial Trailing zeros ##


# Problem Link - 
https://leetcode.com/problems/factorial-trailing-zeroes/description/?envType=study-plan-v2&envId=top-interview-150

# Problem Statement -
Given an integer n, return the number of trailing zeroes in n!.

Note that n! = n * (n - 1) * (n - 2) * ... * 3 * 2 * 1.

# Query/ Code - 
*/

// TC -  (log5 N)
// SC - O(1)

class Solution {
public:
    int trailingZeroes(int n) {
        int divisor = 5;
        int count = 0;
        while(n>= divisor){
            count += n / divisor;
            divisor *= 5;
        }
        return count;
    }
};