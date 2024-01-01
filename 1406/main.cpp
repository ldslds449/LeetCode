/*
 * @lc app=leetcode id=1406 lang=cpp
 *
 * [1406] Stone Game III
 */

#include <vector>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        const int N = stoneValue.size();
        int dp[2][3] = {0};

        for(int i = N-1; i >= 0; --i){
            int sum = 0;
            int alice = -INT32_MAX, bob = INT32_MAX;
            for(int k = 0; k < 3; ++k){
                sum += (i+k < N ? stoneValue[i+k] : 0);
                int bob_pre = (i+k+1 < N ? dp[1][k] : 0);
                int alice_pre = (i+k+1 < N ? dp[0][k] : 0);
                alice = max(alice, sum + bob_pre);
                bob = min(bob, -sum + alice_pre);
            }
            dp[0][2] = dp[0][1]; dp[0][1] = dp[0][0]; dp[0][0] = alice;
            dp[1][2] = dp[1][1]; dp[1][1] = dp[1][0]; dp[1][0] = bob;
        }

        return (dp[0][0] == 0 ? "Tie" : (dp[0][0] > 0 ? "Alice" : "Bob"));
    }
};
// @lc code=end

