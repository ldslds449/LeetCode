/*
 * @lc app=leetcode id=1071 lang=cpp
 *
 * [1071] Greatest Common Divisor of Strings
 */

#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if(str2.size() > str1.size()) swap(str1, str2);
        
        int str1_idx = 0;
        while(true){
            while(str1.size() - str1_idx >= str2.size()){
                for(int i = 0; i < str2.size(); ++i, ++str1_idx){
                    if(str1[str1_idx] != str2[i]) return "";
                }
            }
            if(str1_idx == str1.size()) return str2;
            str1 = str1.substr(str1_idx);
            swap(str1, str2);
            str1_idx = 0;
        }
    }
};
// @lc code=end

