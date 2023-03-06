/*
 * @lc app=leetcode id=909 lang=cpp
 *
 * [909] Snakes and Ladders
 */

#include <vector>
#include <queue>

using namespace std;

// @lc code=start
class Solution {
public:
    inline int& value(vector<vector<int>>& board, int idx){
        int N = board.size();
        int row = idx / N;
        int col = idx % N;
        
        int row_idx = N - row - 1;
        int col_idx = row % 2 ? N - 1 - col : col;
        return board[row_idx][col_idx];
    }

    int snakesAndLadders(vector<vector<int>>& board) {
        int N = board.size();
        int end = N*N-1;

        queue<int> q;
        q.push(0);
        value(board, 0) = -2;

        int step = 0;
        while(!q.empty()){
            int q_size = q.size();
            for(int i = 0; i < q_size; ++i){
                int now = q.front(); q.pop();
                if(now == end) return step;

                for(int k = now+1; k <= min(now+6, end); ++k){
                    int &val = value(board, k);
                    if(val > 0) q.push(val-1);
                    else if(val == -1) q.push(k);
                    val = -2;
                }
            }
            step++;
        }

        return -1;
    }
};
// @lc code=end

