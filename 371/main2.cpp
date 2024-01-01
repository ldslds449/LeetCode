/*
 * @lc app=leetcode id=371 lang=cpp
 *
 * [371] Sum of Two Integers
 */

// @lc code=start
class Solution {
public:
    int getSum(int a, int b) {
      unsigned offset = 1;
      bool c = 0;
      int ans = 0;
      while(a | b | c){
        bool digit_a = a&1;
        bool digit_b = b&1;
        
        if(digit_a ^ digit_b ^ c) ans |= offset;
        c = (digit_a & digit_b) || (digit_a & c) || (digit_b & c);

        offset <<= 1;
        if(!offset) break;
        a >>= 1;
        b >>= 1;
      }
      return ans;
    }
};
// @lc code=end

