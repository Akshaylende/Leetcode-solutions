/*
## 200. Number of Islands ##


# Problem Link - 
https://leetcode.com/problems/number-of-islands/description/?envType=study-plan-v2&envId=top-interview-150

# Problem Statement -
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

# Query/ Code - 
*/
// TC - O(rows * cols)
// SC - O(1)

class Solution {
public:
     void dfs(int x, int y, vector<vector<char>> &grid) {
        grid[x][y] = '0'; //to denote visited
        int dir[] = {0,-1,0,1,0};
        for(int i=0;i<4;i++) {
            int new_x = x + dir[i];
            int new_y = y + dir[i+1];
            if(new_x>=0 && new_y>=0 && new_x < grid.size() && new_y < grid[0].size() && grid[new_x][new_y]=='1')
                dfs(new_x,new_y,grid);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int count=0;
        for(int i=0;i<grid.size();i++) {
            for(int j=0;j<grid[0].size();j++) {
                if(grid[i][j]=='1') {
                    dfs(i,j, grid);
                    count++; //number of components = no of islands
                }
            }
        }
        return count;
    }
};