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
        vector<int> dp(nums2.size()+1, 0);
        vector<int> dp_pre(nums2.size()+1, 0);

        for(int i = 0; i < nums1.size(); ++i){
            for(int k = 1; k <= nums2.size(); ++k){
                dp[k] = max(dp[k-1], dp_pre[k]);
                if(nums1[i] == nums2[k-1]){
                  dp[k] = max(dp[k], dp_pre[k-1]+1);
                }
            }
            dp_pre = dp;
        }

        return dp_pre[nums2.size()];
    }
};
// @lc code=end

