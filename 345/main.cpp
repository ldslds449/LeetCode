/*
 * @lc app=leetcode id=345 lang=cpp
 *
 * [345] Reverse Vowels of a String
 */

#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    bool isVowels(char c){
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }

    string reverseVowels(string s) {
        int front = -1, end = s.size();
        while(true){
            do{
                front++;
            }while(front < s.size() && !isVowels(s[front]));
            do{
                end--;
            }while(end >= 0 && !isVowels(s[end]));
            if(front >= end) break;
            swap(s[front], s[end]);
        }
        return s;
    }
};
// @lc code=end

