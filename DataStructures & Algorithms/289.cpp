/*
## 289. Game of Life ##


# Problem Link - 
https://leetcode.com/problems/game-of-life/description/?envType=study-plan-v2&envId=top-interview-150

# Problem Statement -
According to Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

The board is made up of an m x n grid of cells, where each cell has an initial state: live (represented by a 1) or dead (represented by a 0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

Any live cell with fewer than two live neighbors dies as if caused by under-population.
Any live cell with two or three live neighbors lives on to the next generation.
Any live cell with more than three live neighbors dies, as if by over-population.
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
The next state of the board is determined by applying the above rules simultaneously to every cell in the current state of the m x n grid board. In this process, births and deaths occur simultaneously.

Given the current state of the board, update the board to reflect its next state.

Note that you do not need to return anything.

# Query/ Code - 
*/

// TC - O(m X N)
// SC - O(m X n)

class Solution {
public:

    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<pair<int, int>> ind;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                int count_ones = 0;
                int count_zeros = 0;
                bool alive = board[i][j];
                if(i-1>=0 && j-1>=0){
                    if(board[i-1][j-1] == 1) count_ones++;
                    else count_zeros++;
                } 
                if(i-1>=0){
                    if(board[i-1][j] == 1) count_ones++;
                    else count_zeros++;
                }
                if(i-1>=0 && j+1<n){
                    if(board[i-1][j+1] == 1) count_ones ++;
                    else count_zeros++;
                }
                if(j-1>=0){
                    if(board[i][j-1] == 1) count_ones++;
                    else count_zeros++;
                }
                if(j+1<n){
                     if(board[i][j+1] == 1) count_ones ++;
                    else count_zeros++;
                }
                if(i+1 < m && j-1>=0){
                    if(board[i+1][j-1] == 1) count_ones++;
                    else count_zeros++;
                }
                if(i+1 < m){
                    if(board[i+1][j] == 1) count_ones++;
                    else count_zeros++;
                }
                if(i+1 <m && j+1< n){
                    if(board[i+1][j+1] == 1) count_ones++;
                    else count_zeros++;
                }
                if(alive){
                    if(count_ones < 2 || count_ones > 3){
                        ind.push_back({i,j});
                    }
                }
                else{
                    if(count_ones == 3){
                        ind.push_back({i,j});
                    }
                }
            }
        }
        for(auto [i, j] : ind){
            if(board[i][j] == 1) board[i][j] = 0;
            else board[i][j] = 1;
        }
    }
};


// optimized Inspace solution 
// using -1 and 2 for conversion of live and dead values 


class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                int live_neigh = 0;
                if(i-1>=0){
                    if(j-1>=0){
                        if(board[i-1][j-1]==1 || board[i-1][j-1] == -1) live_neigh++;
                    }
                    if(board[i-1][j] == 1 || board[i-1][j] == -1) live_neigh++; 
                    if(j+1 < n){
                        if(board[i-1][j+1] == 1 || board[i-1][j+1] == -1 ) live_neigh++;
                    }
              }
              if(j-1>=0){
                if(board[i][j-1] == 1 ||board[i][j-1] == -1 ) live_neigh++;
              } 
              if(j+1 < n){
                if(board[i][j+1] == 1 || board[i][j+1] == -1 ) live_neigh++;
              } 
              if(i+1 <m){
                if(j-1>=0){
                    if(board[i+1][j-1] == 1 || board[i+1][j-1] == -1 ) live_neigh++;
                }
                if(board[i+1][j] == 1 or board[i+1][j] == -1) live_neigh++;
                if(j+1<n){
                    if(board[i+1][j+1] == 1 || board[i+1][j+1] == -1) live_neigh++;
                }
              }
              if(board[i][j] == 0 && live_neigh == 3){
                    board[i][j]= 2;
              }
              if(board[i][j] == 1 && (live_neigh <2 || live_neigh > 3)){
                board[i][j] = -1;
              }
            }
        }
        for(int i=0; i< m; i++){
            for(int j=0; j<n;j++){
                if(board[i][j] == -1) board[i][j]=0;
                if(board[i][j]==2) board[i][j] =1;
            }
        }
    }
};