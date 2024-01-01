/*
 * @lc app=leetcode id=991 lang=cpp
 *
 * [991] Broken Calculator
 */

#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int time = 0, ans = INT32_MAX;

        while(true){
            if(startValue >= target){
                ans = min(ans, (startValue-target)+time);
            }
            if(target == 1) break;
            if(target & 1){
                target += 1;
            }else{
                target >>= 1;
            }
            time++;
        }

        return ans;
    }
};
// @lc code=end

