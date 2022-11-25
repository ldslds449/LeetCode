/*
 * @lc app=leetcode id=2131 lang=cpp
 *
 * [2131] Longest Palindrome by Concatenating Two Letter Words
 */

#include <vector>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    inline int hash(string s){
        return (s[0]-'a')*26 + (s[1]-'a');
    }

    int longestPalindrome(vector<string>& words) {
        vector<int> table(26*26, 0);
        for(int i = 0; i < words.size(); ++i){
            table[hash(words[i])]++;
        }

        int total = 0, extra_double = 0;
        for(int i = 0; i < 26*26; ++i){
            if(table[i] <= 0) continue;
            int reverse_hash = (i%26)*26+(i/26);
            if(i == reverse_hash){
                total += table[i]/2;
                if(table[i] & 1) extra_double++;
                table[i] = -1;
            }else{
                int &a_size = table[i];
                int &b_size = table[reverse_hash];
                total += min(a_size, b_size);
                a_size = -1;
                b_size = -1;
            }
        }
        int pair_size = (total << 1) + (extra_double > 0);

        return pair_size << 1;
    }
};
// @lc code=end

