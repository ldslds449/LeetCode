/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
        if(n <= 1) return n;
        long long a = 1, b = 2;
        for(int i = 1; i < n; ++i){
            long long tmp = a + b;
            a = b;
            b = tmp;
        }
        return a;
    }
};
// @lc code=end

