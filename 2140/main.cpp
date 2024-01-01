/*
 * @lc app=leetcode id=2140 lang=cpp
 *
 * [2140] Solving Questions With Brainpower
 */

#include <vector>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int N = questions.size();
        vector<long long> dp(N, 0);

        dp[N-1] = questions[N-1][0];
        for(int i = N-2; i >= 0; i--){
            long long pre = i + questions[i][1] + 1 < N ? dp[i + questions[i][1] + 1] : 0;
            dp[i] = max(dp[i+1], pre + questions[i][0]);
        }

        return dp[0];
    }
};
// @lc code=end

