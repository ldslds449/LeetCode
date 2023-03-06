/*
 * @lc app=leetcode id=6 lang=cpp
 *
 * [6] Zigzag Conversion
 */

#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> strs(numRows, "");

        int idx = 0, tmp; int offset = -1;
        for(int i = 0; i < s.size(); i++){
            strs[idx] += s[i];
            tmp = 0;
            if(idx == numRows-1 ){
                offset *= -1;
                tmp += offset;
            }
            if(idx == 0){
                offset *= -1;
                tmp += offset;
            } 
            if(idx != 0 && idx != numRows-1){
                tmp += offset;
            }
            idx += tmp;
        }

        string r = "";
        for(string &tmp : strs){
            r += tmp;
        }
        return r;
    }
};
// @lc code=end

