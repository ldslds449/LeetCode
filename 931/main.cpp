/*
 * @lc app=leetcode id=931 lang=cpp
 *
 * [931] Minimum Falling Path Sum
 */

#include <vector>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        for(int i = matrix.size()-1-1; i >= 0; --i){
            for(int j = 0; j < matrix[i].size(); ++j){
                int min_val = matrix[i+1][j];
                if(j-1 >= 0) min_val = min(min_val, matrix[i+1][j-1]);
                if(j+1 < matrix[i].size()) min_val = min(min_val, matrix[i+1][j+1]);
                matrix[i][j] += min_val;
            }
        }

        return *min_element(matrix[0].begin(), matrix[0].end());
    }
};
// @lc code=end

