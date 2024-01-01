/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 */

#include <vector>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int start_0 = 0, start_2 = nums.size()-1;

        for(int i = 0; i <= start_2; ++i){
            if(nums[i] == 0){
                swap(nums[i], nums[start_0++]);
            }else if(nums[i] == 2){
                swap(nums[i], nums[start_2--]);
                i--;
            }
        }
    }
};
// @lc code=end

