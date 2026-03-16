/*
## 74. Search in a 2D Matrix ##


# Problem Link - 
https://leetcode.com/problems/search-a-2d-matrix/description/?envType=study-plan-v2&envId=top-interview-150

# Problem Statement -
You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.

# Query/ Code - 
*/
// TC - O(N logn)
// SC - O(1)

class Solution {
public:
    bool binarySearch(vector<int>& arr, int low, int high, int target){
        //cout<< low << " "<< high<< endl;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(arr[mid] == target) return true;
            if(arr[mid]>target) high = mid-1;
            else low = mid+1;
        }
        return false; 
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i=0; i<m; i++){
            if(matrix[i][n-1]>= target){
                return binarySearch(matrix[i], 0, n-1, target);               
            }
        }
        return false;
    }
};

# Approach 2  Optimized singly handed Binary search by flattening the matrix

// TC - O(log m*n)
// SC - O(1)

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int low = 0 , high = m * n-1;
        while(low <= high){
            int mid = low + (high-low)/2;
            int row = mid / n;
            int col = mid % n;

            if(matrix[row][col] == target) return true;
            if(matrix[row][col] < target) low = mid+1;
            else high = mid-1;
        }
        return false;
    } 
};

// Approach - 
1. flatten the matrix into a linear vector or array
2. keep the track for low and high pointer with high pointing to last element
3. loop it and get a row as mid/n && col as mid % n 
4. check if row and col index element is target then true
5. else if target is greater then low = mid +1 or else high = mid -1
