/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 */

#include <string>
#include <cctype>

using namespace std;

// @lc code=start
class Solution {
public:
    bool isPalindrome(string s) {
        int front = 0, end = s.size()-1;

        while(true){
            while(front < s.size() && !isalnum(s[front])) front++;
            while(end >= 0 && !isalnum(s[end])) end--;
            if(front >= end) break;
            if(tolower(s[front]) != tolower(s[end])) return false;
            front++; end--;
        }

        return true;
    }
};
// @lc code=end

