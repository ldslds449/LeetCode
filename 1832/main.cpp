/*
 * @lc app=leetcode id=1832 lang=cpp
 *
 * [1832] Check if the Sentence Is Pangram
 */

#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<bool> seen(26, false);
        int see_cnt = 0;
        for(char c : sentence){
            if(!seen[c-'a']){
                seen[c-'a'] = true;
                see_cnt++;
            }
        }
        return see_cnt == 26;
    }
};
// @lc code=end

