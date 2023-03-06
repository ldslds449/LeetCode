/*
 * @lc app=leetcode id=918 lang=cpp
 *
 * [918] Maximum Sum Circular Subarray
 */

#include <vector>
#include <climits>

using namespace std;

// @lc code=start
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int tmp = 0, max_val = INT_MIN, total = 0;
        for(int i = 0; i < nums.size(); ++i){
            tmp = max(tmp+nums[i], nums[i]);
            max_val = max(tmp, max_val);
            total += nums[i];
        }

        int min_val = INT_MAX;
        for(int i = 1; i < nums.size()-1; ++i){
            tmp = min(tmp+nums[i], nums[i]);
            min_val = min(tmp, min_val);
        }

        return max(max_val, total-min_val);
    }
};
// @lc code=end

