/*
 * @lc app=leetcode id=377 lang=cpp
 *
 * [377] Combination Sum IV
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned long long> dp(target+1, 0);
        dp[0] = 1;
        for(int i = 1; i <= target; ++i){
            for(int &n : nums){
                int lookup = i - n;
                if(lookup < 0) continue;
                dp[i] += dp[lookup];
            }
        }
        return dp[target];
    }
};
// @lc code=end

