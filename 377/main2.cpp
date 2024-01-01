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
    int dfs(vector<int>& nums, int target, vector<int> &dp) {
        if(target == 0) return 1;
        else if(target < 0) return 0;
        else if(dp[target] >= 0) return dp[target];
        int count = 0;
        for(int &n : nums){
            count += dfs(nums, target - n, dp);
        }
        return dp[target] = count;
    }

    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1, -1);
        return dfs(nums, target, dp);
    }
};
// @lc code=end

