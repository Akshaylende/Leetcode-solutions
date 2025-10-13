/*
## 130. Surrounded Regions ##


# Problem Link - 
https://leetcode.com/problems/surrounded-regions/?envType=study-plan-v2&envId=top-interview-150

# Problem Statement -
You are given an m x n matrix board containing letters 'X' and 'O', capture regions that are surrounded:

Connect: A cell is connected to adjacent cells horizontally or vertically.
Region: To form a region connect every 'O' cell.
Surround: The region is surrounded with 'X' cells if you can connect the region with 'X' cells and none of the region cells are on the edge of the board.
To capture a surrounded region, replace all 'O's with 'X's in-place within the original board. You do not need to return anything

# Query/ Code - 
*/
// TC - O(m*n)
// SC - O(1)
class Solution {
public:
    void DFS(int x, int y, vector<vector<char>>& board){
        board[x][y] = 'X';
        int r = board.size();
        int c = board[0].size();
        int dir[5] = {0, -1, 0, 1, 0};
        for(int i=0; i<4; i++){
            int new_x = x + dir[i];
            int new_y = y + dir[i+1];
            if(new_x < r && new_y < c  && new_x >=0  && new_y >= 0 && board[new_x][new_y] == 'O')
                DFS(new_x, new_y, board);
        }

    }
    void solve(vector<vector<char>>& board) {
        int r = board.size();
        int c = board[0].size();
        for(int i=1; i<r-1; i++){
            for(int j=1; j<c-1; j++){
                if(board[i][j] == 'O'){
                    DFS(i, j, board);
                }
            }
        }
    }
};