/*
## 36. Valid Sudoku ##


# Problem Link - 
https://leetcode.com/problems/valid-sudoku/description/?envType=study-plan-v2&envId=top-interview-150

# Problem Statement -
Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
Note:

A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules.

# Query/ Code - 
*/
TC - O(9*9)
SC - O(9+9+9)

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int,unordered_set<char>> row, col, block;
        int m = board.size();
        int n = board[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] != '.'){
                    char digit = board[i][j];
                    int block_ind = (i/3)*3 + (j/3);
                    if(row[i].find(digit) != row[i].end()) return false;
                    if(col[j].find(digit) != col[j].end()) return false;
                    if(block[block_ind].find(digit) != block[block_ind].end()) return false;
                    row[i].insert(digit);
                    col[j].insert(digit); 
                    block[block_ind].insert(digit);
                }
            }
        }
        return true;
    }
};