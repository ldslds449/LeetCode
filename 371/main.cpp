/*
 * @lc app=leetcode id=371 lang=cpp
 *
 * [371] Sum of Two Integers
 */

// @lc code=start
class Solution {
public:
    int getSum(int a, int b) {
      int AND = a & b;
      int tmp = a ^ b;
      if(!AND) return tmp;
      return getSum(tmp, (unsigned)AND << 1);
    }
};
// @lc code=end

