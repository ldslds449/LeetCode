/*
 * @lc app=leetcode id=74 lang=cpp
 *
 * [74] Search a 2D Matrix
 */

#include <vector>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        vector<int> first;
        for(int i = 0; i < matrix.size(); ++i){
            first.push_back(matrix[i][0]);
        }

        auto it = upper_bound(first.begin(), first.end(), target);
        if(it == first.begin()) return false;

        int idx = it - first.begin() - 1;
        auto it2 = lower_bound(matrix[idx].begin(), matrix[idx].end(), target);

        return it2 != matrix[idx].end() && *it2 == target;
    }
};
// @lc code=end

