/*
 * @lc app=leetcode id=36 lang=cpp
 *
 * [36] Valid Sudoku
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; ++i){
            vector<bool> table_row(9, 0), table_col(9, 0);
            for(int j = 0; j < 9; ++j){
                if(board[i][j] != '.'){
                    if(table_row[board[i][j]-'1']) return false;
                    table_row[board[i][j]-'1'] = true;
                }
                if(board[j][i] != '.'){
                    if(table_col[board[j][i]-'1']) return false;
                    table_col[board[j][i]-'1'] = true;
                }
            }
        }
        for(int i = 0; i < 9; ++i){
            vector<bool> table(9, 0);
            for(int j = 0; j < 9; ++j){
                int row = (i / 3) * 3 + (j / 3);
                int col = (i % 3) * 3 + (j % 3);
                if(board[row][col] == '.') continue;
                if(table[board[row][col]-'1']) return false;
                table[board[row][col]-'1'] = true;
            }
        }
        return true;
    }
};
// @lc code=end

