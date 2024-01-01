/*
 * @lc app=leetcode id=45 lang=cpp
 *
 * [45] Jump Game II
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int jump(vector<int>& nums) {
      if(nums.size() <= 1) return 0;
      int start = 0, end = 1;
      int step = 1, target = nums.size()-1;
      while(true){
        int far = -1;
        for(int i = start; i < end; ++i){
          far = max(far, i + nums[i]);
        }
        if(far >= target) break;
        start = end;
        end = far+1;
        step++;
      }

      return step;
    }
};
// @lc code=end

