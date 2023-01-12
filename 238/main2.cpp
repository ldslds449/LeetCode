/*
 * @lc app=leetcode id=238 lang=cpp
 *
 * [238] Product of Array Except Self
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        vector<int> ans(nums.size());
        for(int i = 0, num = 1; i < nums.size(); ++i){
            ans[i] = num;
            num *= nums[i];
        }
        for(int i = nums.size()-1, num = 1; i >= 0; --i){
            ans[i] *= num;
            num *= nums[i];
        }
        return ans;
    }
};
// @lc code=end

