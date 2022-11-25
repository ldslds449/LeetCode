/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 */

#include <vector>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    bool DFS(vector<vector<char>>& board, vector<vector<int>>& ing, int i, int j, string word){
        if(board[i][j] != word.front()) return false;
        word = word.substr(1);
        if(word.size() == 0) return true;
        ing[i][j] = 1;

        const int x_offset[] = {1, 0, -1, 0};
        const int y_offset[] = {0, 1, 0, -1};

        for(int k = 0; k < 4; ++k){
            int new_i = x_offset[k] + i;
            int new_j = y_offset[k] + j;
            if(new_i < 0 || new_i >= board.size()) continue;
            if(new_j < 0 || new_j >= board.front().size()) continue;
            if(ing[new_i][new_j] == 1) continue;
            bool r = DFS(board, ing, new_i, new_j, word);
            if(r) return true;
        }
        
        ing[i][j] = 0;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int M = board.size();
        int N = board.front().size();
        vector<vector<int>> ing(M, vector<int>(N, 0));

        for(int i = 0; i < M; ++i){
            for(int j = 0; j < N; ++j){
                if(DFS(board, ing, i, j, word)) return true;
            }
        }
        return false;
    }
};
// @lc code=end

