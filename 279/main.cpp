/*
 * @lc app=leetcode id=279 lang=cpp
 *
 * [279] Perfect Squares
 */

#include <cmath>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution {
public:
    unordered_map<int,int> table;

    int numSquares(int n) {
        if(n == 0) return 0;
        if(table.count(n)) return table[n];
        int square = floor(sqrt(n));
        int min_val = 99999;
        for(int i = 1; i <= square; ++i){
            min_val = min(min_val, 1 + numSquares(n - i*i));
        }
        table[n] = min_val;
        return min_val;
    }
};
// @lc code=end

