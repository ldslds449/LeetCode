/*
 * @lc app=leetcode id=1704 lang=cpp
 *
 * [1704] Determine if String Halves Are Alike
 */

#include <string>
#include <bitset>

using namespace std;

// @lc code=start
class Solution {
public:
    bool halvesAreAlike(string s) {
        bitset<255> vowel_bit;
        vowel_bit['a'] = true;
        vowel_bit['e'] = true;
        vowel_bit['i'] = true;
        vowel_bit['o'] = true;
        vowel_bit['u'] = true;
        vowel_bit['A'] = true;
        vowel_bit['E'] = true;
        vowel_bit['I'] = true;
        vowel_bit['O'] = true;
        vowel_bit['U'] = true;
        
        int vowel = 0;
        for(int i = 0; i < s.size()/2; ++i){
            if(vowel_bit[s[i]]) vowel++;
        }

        for(int i = s.size()/2; i < s.size(); ++i){
            if(vowel_bit[s[i]]) vowel--;
        }

        return vowel == 0;
    }
};
// @lc code=end

