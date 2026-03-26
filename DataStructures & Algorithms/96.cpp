/*
## 96. Unique Binary Search Trees ##


# Problem Link - 
https://leetcode.com/problems/unique-binary-search-trees/description/?envType=problem-list-v2&envId=tree

# Problem Statement -
Given an integer n, return the number of structurally unique BST's (binary search trees) which has exactly n nodes of unique values from 1 to n.


# Query/ Code - 
*/
// TC - O(n2)
// SC - O(n)
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1, 1);
        for(int i=2; i<n+1; i++){
            int total = 0;
            for(int j=1; j<=i; j++){
                int left = j-1;
                int right = i - j;
                total += dp[left] * dp[right];
            }
            dp[i] = total;
        }
        return dp[n];
    }
};

# Approach -
1. Initialize dp of size n+1,  with 1
2. Iterate in a for loop from  2 to n 
3. calculate total by iterating from j = 1 to j <=i and consider left as j - 1 and right as i-j 
4. store the dp[i] = dp[left] * dp[right]
