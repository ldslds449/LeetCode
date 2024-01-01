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
    int bs_row(vector<vector<int>>& matrix, int target){
        int start = 0, end = matrix.size();
        while(start < end){
            int mid = start + (end - start) / 2;
            if(matrix[mid][0] < target){
                start = mid+1;
            }else if(target < matrix[mid][0]){
                end = mid;
            }else{
                start = mid+1;
            }
        }
        return start;
    }

    int bs_col(vector<int>& matrix, int target){
        int start = 0, end = matrix.size();
        while(start < end){
            int mid = start + (end - start) / 2;
            if(matrix[mid] < target){
                start = mid+1;
            }else if(target < matrix[mid]){
                end = mid;
            }else{
                return mid;
            }
        }
        return -1;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row_idx = bs_row(matrix, target);
        if(row_idx == 0) return false;

        int col_idx = bs_col(matrix[row_idx-1], target);
        return col_idx != -1;
    }
};
// @lc code=end

