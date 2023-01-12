/*
 * @lc app=leetcode id=944 lang=cpp
 *
 * [944] Delete Columns to Make Sorted
 */

#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int count = 0;
        for(int i = 0; i < strs[0].size(); ++i){
            for(int j = 1; j < strs.size(); ++j){
                if(strs[j][i] - strs[j-1][i] < 0){
                    count++; break;
                }
            }
        }
        return count;
    }
};
// @lc code=end

