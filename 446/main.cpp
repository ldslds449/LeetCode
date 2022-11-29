/*
 * @lc app=leetcode id=446 lang=cpp
 *
 * [446] Arithmetic Slices II - Subsequence
 */

#include <vector>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution {
public:

    int numberOfArithmeticSlices(vector<int>& nums) {
        vector<unordered_map<long,int>> dp(nums.size());

        for(int i = 0; i < nums.size(); ++i){
            for(int j = 0; j < i; ++j){
                long diff = (long)nums[i] - nums[j];
                dp[i][diff] += dp[j][diff] + 1;
            }
        }

        int total = 0;
        for(int i = 0; i < nums.size(); ++i){
            for(auto p : dp[i]){
                total += p.second;
            }
        }
        total -= (nums.size()*(nums.size()-1))/2;

        return total;
    }
};
// @lc code=end

