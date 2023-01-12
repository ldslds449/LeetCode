/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 */

#include <string>
#include <stack>
#include <cctype>

using namespace std;

// @lc code=start
class Solution {
public:
    bool isPalindrome(string s) {
        stack<char> st;
        for(char c : s){
            if(isalnum(c)){
                st.push(tolower(c));
            }
        }
        for(char c : s){
            if(isalnum(c)){
                if(st.top() != tolower(c)){
                    return false;
                }
                st.pop();
            }
        }
        return true;
    }
};
// @lc code=end

