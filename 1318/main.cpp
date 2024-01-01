/*
 * @lc app=leetcode id=1318 lang=cpp
 *
 * [1318] Minimum Flips to Make a OR b Equal to c
 */

// @lc code=start
class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans = 0;
        int tmp = (a | b) ^ c;
        while(tmp){
            int idx =  __builtin_ctz(tmp);
            if((c >> idx) & 1){
                ans += 1;
            }else{
                ans += ((a >> idx) & 1) + ((b >> idx) & 1);
            }
            tmp ^= (tmp & -tmp);
        }
        return ans;
    }
};
// @lc code=end

