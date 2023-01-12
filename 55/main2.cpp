/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 */

#include <vector>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<short> table;

    bool helper(vector<int> &nums, int now){
        if(now == 0) return true;
        for(int i = now-1; i >= 0; --i){
            if(nums[i] + i < now) continue;
            bool r;
            if(table[i] >= 0) r = table[i];
            else{
                r = helper(nums, i);
                table[i] = r;
            }
            if(r) return true;
        }
        return false;
    }

    bool canJump(vector<int>& nums) {
        table.assign(10001, -1);
        return helper(nums, nums.size()-1);
    }
};
// @lc code=end

