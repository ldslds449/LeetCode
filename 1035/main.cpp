/*
 * @lc app=leetcode id=1035 lang=cpp
 *
 * [1035] Uncrossed Lines
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size()+1, vector<int>(nums2.size()+1, 0));

        for(int i = 1; i <= nums1.size(); ++i){
            for(int k = 1; k <= nums2.size(); ++k){
                dp[i][k] = max(dp[i-1][k], dp[i][k-1]);
                if(nums1[i-1] == nums2[k-1]){
                    dp[i][k] = max(dp[i][k], dp[i-1][k-1]+1);
                }
            }
        }

        return dp[nums1.size()][nums2.size()];
    }
};
// @lc code=end

