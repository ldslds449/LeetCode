/*
 * @lc app=leetcode id=1470 lang=cpp
 *
 * [1470] Shuffle the Array
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> r(2*n);
        for(int i = 0; i < n; ++i){
            r[i*2] = nums[i];
            r[i*2+1] = nums[i+n];
        }
        return r;
    }
};
// @lc code=end

