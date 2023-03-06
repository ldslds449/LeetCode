/*
 * @lc app=leetcode id=1137 lang=cpp
 *
 * [1137] N-th Tribonacci Number
 */

// @lc code=start
class Solution {
public:
    int tribonacci(int n) {
        if(n == 0) return 0;
        else if(n <= 2) return 1;

        int a = 0, b = 1, c = 1;
        while(n - 2){
            n--;
            int tmp = a + b + c;
            a = b;
            b = c;
            c = tmp;
        }

        return c;
    }
};
// @lc code=end

