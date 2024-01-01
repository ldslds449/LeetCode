/*
 * @lc app=leetcode id=1547 lang=cpp
 *
 * [1547] Minimum Cost to Cut a Stick
 */

#include <vector>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(), cuts.end());

        int N = cuts.size();
        vector<int> diff(N, 0);
        int pre = 0;
        for(int i = 0; i < N; ++i){
            diff[i] = cuts[i] - pre;
            pre = cuts[i];
        }
        diff.push_back(n - pre);

        vector<vector<int>> dp(N+1, vector<int>(N+1, 0));
        for(int i = 1; i <= N; ++i){ // length
            for(int start = 0; start < N+1; ++start){ // start
                if(start+i >= N+1) continue;
                int end = start + i;
                int min_val = INT32_MAX;
                int sum = diff[start];
                for(int k = 0; k < i; ++k){ // break point
                    int left_e = start + k;
                    int right_s = left_e + 1;
                    min_val = min(min_val, dp[start][left_e] + dp[right_s][end]);
                    sum += diff[right_s];
                }
                dp[start][end] = min_val + sum;
            }
        }

        return dp[0][N];
    }
};
// @lc code=end

