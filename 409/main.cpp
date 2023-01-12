/*
 * @lc app=leetcode id=409 lang=cpp
 *
 * [409] Longest Palindrome
 */

#include <string>
#include <cctype>

using namespace std;

// @lc code=start
class Solution {
public:
    int longestPalindrome(string s) {
        int count[52] = {0};
        for(char c : s){
            if(isupper(c)){
                count[c-'A'+26]++;
            }else{
                count[c-'a']++;
            }
        }
        int len = 0; bool odd = false;
        for(int i = 0; i < 52; ++i){
            len += count[i] & ~(1);
            if(count[i]%2 == 1 && !odd){
                len++; odd = true;
            }
        }
        return len;
    }
};
// @lc code=end

