/*
## 54. Spiral Matrix ##


# Problem Link - 
https://leetcode.com/problems/game-of-life/description/?envType=study-plan-v2&envId=top-interview-150

# Problem Statement -
Given an m x n matrix, return all elements of the matrix in spiral order.

# Query/ Code - 
*/
// TC - O(m X n)
// SC - O(1) 
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int m = matrix.size();
        int n = matrix[0].size();
        int row = 0, col = 0;
        while(row<m && col<n){
            for(int j=col; j<n; j++){
                result.push_back(matrix[row][j]);
            }
            row++;
            for(int i = row; i<m; i++){
                result.push_back(matrix[i][n-1]);
            }
            n--;
            if(row<m){   // here not checking the column 
                for(int j=n-1; j>=col; j--){
                    result.push_back(matrix[m-1][j]);
                }
                m--;
            }
            
            if(col<n){  // here not checking the row
                for(int i = m-1 ; i>=row; i--){
                    result.push_back(matrix[i][col]);
                }
                col++;
            }
            
        }
        return result;
    }
};