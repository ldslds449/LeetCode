/*
 * @lc app=leetcode id=38 lang=cpp
 *
 * [38] Count and Say
 */

#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    string countAndSay(int n) {
        string s;
        for(int i = 0; i < n; ++i){
            if(i == 0){
                s = "1"; continue;
            }
            char prev = s[0]; int cnt = 1;
            string new_str = "";
            for(int i = 1; i <= s.size(); ++i){
                if(i == s.size() || s[i] != prev){
                    new_str += to_string(cnt) + to_string(prev-'0');
                    cnt = 1;
                    if(i < s.size()) prev = s[i];
                }else{
                    cnt++;
                }
            }
            s = new_str;
        }
        return s;
    }
};
// @lc code=end

