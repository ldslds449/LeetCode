/*
 * @lc app=leetcode id=899 lang=cpp
 *
 * [899] Orderly Queue
 */

#include <string>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k == 0) return s;
        else if(k == 1){
            string small = s;
            for(int i = 1; i < s.size(); ++i){
                small = min(small, string(s.begin()+i, s.end()) + string(s.begin(), s.begin()+i));
            }
            return small;
        }
        sort(s.begin(), s.end());
        return s;
    }
};
// @lc code=end

