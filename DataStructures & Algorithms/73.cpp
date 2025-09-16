/*
## 73. Set Matrix zeros ##


# Problem Link - 
https://leetcode.com/problems/set-matrix-zeroes/description/?envType=study-plan-v2&envId=top-interview-150

# Problem Statement -
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

You must do it in place.

# Query/ Code - 
*/

// TC - O(m*n)
// SC - O(m+n)

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> rows(m, 1), cols(n, 1);
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j] == 0){
                    rows[i] = 0;
                    cols[j] = 0;
                }
            }
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(rows[i] == 0 || cols[j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};



#optimized O(1) Approach 
TC - O(m*n)
SC - O(1)
// marking the first row and column to be zero and then replicating it 
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int first_cell = 1;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j] == 0){
                    if(i == 0){
                        first_cell = 0;
                    }
                    else{
                        matrix[i][0] = 0; // row
                        matrix[0][j] = 0; // col 
                    }
                }
            }
        }
        for(int i=1;i<m;i++){
            for(int j=1; j<n; j++){
                if(matrix[i][0] == 0){
                    matrix[i][j] = 0;
                }
                if(matrix[0][j]==0){
                    matrix[i][j]=0;
                }
            }
        }
        if(matrix[0][0] == 0){
            for(int i=0; i<m;i++){
                matrix[i][0] = 0;
            }
        }
        if(first_cell == 0){
            for(int j = 0; j<n;j++){
                matrix[0][j]=0;
            }
        }
        
    }
};