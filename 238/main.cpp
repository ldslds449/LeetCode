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
        vector<int> prefix(nums.size());
        vector<int> suffix(nums.size());

        for(int i = 0, num = 1; i < nums.size(); ++i){
            prefix[i] = num;
            num *= nums[i];
        }
        for(int i = nums.size()-1, num = 1; i >= 0; --i){
            suffix[i] = num;
            num *= nums[i];
        }

        for(int i = 0; i < nums.size(); ++i){
            nums[i] = prefix[i] * suffix[i];
        }
        return nums;
    }
};
// @lc code=end

