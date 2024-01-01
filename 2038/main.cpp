/*
 * @lc app=leetcode id=2038 lang=cpp
 *
 * [2038] Remove Colored Pieces if Both Neighbors are the Same Color
 */

#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    bool winnerOfGame(string colors) {
        int cnt = 0, pre = ' ', a = 0, b = 0;
        for(int i = 0; i <= colors.size(); ++i){
            if(i == colors.size() || colors[i] != pre){
                (pre == 'A' ? a : b) += max(cnt-2, 0);
                pre = colors[i];
                cnt = 0;
            }
            cnt++;
        }

        return a > b;
    }
};
// @lc code=end

