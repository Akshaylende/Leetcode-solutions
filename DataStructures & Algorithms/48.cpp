/*
## 48. Rotate Image ##


# Problem Link - 
https://leetcode.com/problems/rotate-image/?envType=study-plan-v2&envId=top-interview-150

# Problem Statement -
You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

# Query/ Code - 
*/

// TC - O(m X n)
// SC - O(1)

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int M = matrix.size();
        int N = matrix[0].size();
        for(int i=0; i<M; i++){
            for(int j = i; j<N; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for(int i=0; i<M; i++){
            for(int j = 0; j<N/2; j++){
                swap(matrix[i][j], matrix[i][N-1-j]);
            }
        }
    }
};