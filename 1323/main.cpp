/*
 * @lc app=leetcode id=1323 lang=cpp
 *
 * [1323] Maximum 69 Number
 */

#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    int maximum69Number (int num) {
        string s = to_string(num);
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == '6'){
                s[i] = '9';
                return stoi(s);
            }
        }
        return num;
    }
};
// @lc code=end

