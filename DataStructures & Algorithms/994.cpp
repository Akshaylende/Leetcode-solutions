/*
## 994. Rotting Oranges ##


# Problem Link - 
https://leetcode.com/problems/rotting-oranges/description/

# Problem Statement -
You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

# Query/ Code - 
*/
// Time complexity - O(N*M)
// Space Complexity  - O(N*M)

class Solution {
public:
    bool checkValid(int x, int y, int rows, int cols){
        if(x < 0 || y < 0 || x >= rows || y >= cols) return false;
        return true;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int time = 0;
        int fresh = 0;
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        for(int i=0; i<n;i++){
            for(int j =0; j<m; j++){
                if(grid[i][j] ==  1) fresh++;
                if(grid[i][j] == 2) q.push({i, j});
            }
        }
        q.push({-1, -1});
        while(!q.empty()){
            auto [x, y] = q.front();
            q.pop();
            if(x == -1 && y == -1){
                if(!q.empty()){
                    time++;
                    q.push({-1, -1});
                }
                continue;
            }
            if(checkValid(x-1, y, n, m) && grid[x-1][y] == 1){
                grid[x-1][y] = 2;
                q.push({x-1, y});
                fresh--;
            } 
            if(checkValid(x, y+1, n, m) && grid[x][y+1] == 1){
                grid[x][y+1] = 2;
                q.push({x, y+1});
                fresh--;
            } 
            if(checkValid(x+1, y, n, m) && grid[x+1][y] == 1){
                grid[x+1][y] = 2;
                q.push({x+1, y});
                fresh--;
            } 
            if(checkValid(x, y-1, n, m) && grid[x][y-1] == 1){
                grid[x][y-1] = 2;
                q.push({x, y-1});
                fresh--;
            } 
        }
        return fresh == 0 ? time : -1;
    }
};