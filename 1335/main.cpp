/*
 * @lc app=leetcode id=1335 lang=cpp
 *
 * [1335] Minimum Difficulty of a Job Schedule
 */

#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    int table[301][11];

    int dfs(vector<int> &jobDifficulty, int idx, int d){
        // cerr << idx << " " << d << "\n";
        if(jobDifficulty.size() - idx < d) return -1;
        if(d <= 0) return (idx < jobDifficulty.size() ? -1 : 0);
        if(table[idx][d] != -1) return table[idx][d];

        int max_diff = jobDifficulty[idx], total = INT32_MAX;
        for(int i = idx+1; i <= jobDifficulty.size(); ++i){
            int r = dfs(jobDifficulty, i, d-1);
            if(r != -1){
                total = min(total, r + max_diff);
            }
            if(i == jobDifficulty.size()) break;
            max_diff = max(max_diff, jobDifficulty[i]);
        }

        table[idx][d] = total;
        return total;
    }

    int minDifficulty(vector<int>& jobDifficulty, int d) {
        if(jobDifficulty.size() < d) return -1;
        memset(table, -1, sizeof(table));
        return dfs(jobDifficulty, 0, d);
    }
};
// @lc code=end

int main(){
    Solution s;
    vector<int> diff{0,0,0};
    s.minDifficulty(diff, 2);
}
