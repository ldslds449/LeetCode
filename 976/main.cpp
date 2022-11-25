/*
 * @lc app=leetcode id=976 lang=cpp
 *
 * [976] Largest Perimeter Triangle
 */

#include <vector>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        // sort
        sort(nums.begin(), nums.end(), [](int &a, int &b)->bool{
            return a > b;
        });
        // find largest edge
        for(int i = 0; i < nums.size()-2; ++i){
            if(nums[i] >= nums[i+1] + nums[i+2]){
                continue;
            }
            return nums[i] + nums[i+1] + nums[i+2];
        }
        return 0;
    }
};
// @lc code=end

