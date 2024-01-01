/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size()-1;
        int max_water = 0;
        while(left < right){
            int water = min(height[left], height[right]) * (right-left);
            max_water = max(max_water, water);
            if(height[left] < height[right]) left++;
            else right--;
        }

        return max_water;
    }
};
// @lc code=end

