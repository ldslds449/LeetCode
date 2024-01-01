/*
 * @lc app=leetcode id=59 lang=cpp
 *
 * [59] Spiral Matrix II
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if(n == 1) return {{1}};

        vector<vector<int>> m(n, vector<int>(n));
        int total = 1;
        int len = n-1;
        int left = 0, right = n-1, top = 0, bottom = n-1;
        int max = n*n;

        while(total <= max){
            for(int i = 0; i < len && total <= max; ++i){
                m[top][left + i] = total++;
            } top++;
            for(int i = 0; i < len && total <= max; ++i){
                m[i][right + top - 1] = total++;
            } right--;
            for(int i = 0; i < len && total <= max; ++i){
                m[bottom][right - i + 1] = total++;
            } bottom--;
            for(int i = 0; i < len && total <= max; ++i){
                m[bottom - i + 1][left] = total++;
            } left++;
            len--;
        }

        return m;
    }
};
// @lc code=end

