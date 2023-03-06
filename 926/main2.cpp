/*
 * @lc app=leetcode id=926 lang=cpp
 *
 * [926] Flip String to Monotone Increasing
 */

#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    int minFlipsMonoIncr(string s) {

        int val = 0, min_val = 0, count = 0;
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == '0'){
                val--; count++;
            } else val++;
            min_val = min(min_val, val);
        }

        return min_val + count;
    }
};
// @lc code=end

