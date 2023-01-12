/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

#include <vector>
#include <climits>

using namespace std;

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_val = INT_MIN;

        int max_tmp = 0;
        for(auto &n : nums){
            max_tmp = max(max_tmp + n, n);
            max_val = max(max_val, max_tmp);
        }

        return max_val;
    }
};
// @lc code=end

