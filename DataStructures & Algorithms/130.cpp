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
    void DFS(int x, int y, vector<vector<bool>>& visit, vector<vector<char>>& board){
        int dir[] = {0, -1, 0, 1, 0};
        int r = board.size();
        int c = board[0].size();
        visit[x][y] = true;
        for(int i=0; i<4; i++){
            int new_x = x + dir[i];
            int new_y = y + dir[i+1];
            if(new_x >= 0 && new_x < r && new_y >=0 && new_y < c && board[new_x][new_y] == 'O'  && !visit[new_x][new_y] ){
                DFS(new_x, new_y, visit, board);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int r = board.size();
        int c = board[0].size();
        vector<vector<bool>> visit(r, vector<bool> (c, false));
        int i = 0;
        for(int j = 0; j<c; j++){
            if(board[i][j] == 'O' && !visit[i][j]){
                DFS(i, j, visit, board);
            }
            if(board[r-1][j]=='O' && !visit[r-1][j])
                DFS(r-1, j, visit, board);
        }
        int j=0;
        for(int i=0; i<r; i++){
            if(board[i][j] == 'O' && !visit[i][j]){
                DFS(i, j, visit, board);
            }
            if(board[i][c-1]=='O' && !visit[i][c-1])
                DFS(i, c-1, visit, board);
        }

        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(board[i][j] == 'O' && !visit[i][j]){
                    board[i][j] = 'X';
                }
            }
        }

    }
};