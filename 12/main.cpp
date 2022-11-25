/*
 * @lc app=leetcode id=12 lang=cpp
 *
 * [12] Integer to Roman
 */

#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    string helper(string char1, string char2, string char3, int num){
        if(num == 9){
            return char1 + char3;
        }else if(num == 4){
            return char1 + char2;
        }
        string str = (num >= 5 ? char2 : "");
        for(int i = 0; i < num%5; ++i){
            str += char1;
        }
        return str;
    }

    string intToRoman(int num) {
        const string strs[][3] = {
            {"I", "V", "X"},
            {"X", "L", "C"},
            {"C", "D", "M"},
            {"M", "?", "?"}
        };
        const int limit[4] = {1, 10, 100, 1000};
        string r = "";
        for(int i = 3; i >= 0; --i){
            if(num >= limit[i]){
                r += helper(strs[i][0], strs[i][1], strs[i][2], num / limit[i]);
                num %= limit[i];
            }
        }
        return r;
    }
};
// @lc code=end

