/*
 * @lc app=leetcode id=1662 lang=cpp
 *
 * [1662] Check If Two String Arrays are Equivalent
 */

#include <vector>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int str_idx1 = 0, str_idx2 = 0;
        int char_idx1 = 0, char_idx2 = 0;

        while(true){
            if((str_idx1 >= word1.size()) | (str_idx2 >= word2.size())){
                return !((str_idx1 >= word1.size()) ^ (str_idx2 >= word2.size()));
            }

            if(word1[str_idx1][char_idx1] != word2[str_idx2][char_idx2]){
                return false;
            }
            char_idx1++;
            char_idx2++;

            if(char_idx1 >= word1[str_idx1].size()){
                str_idx1++;
                char_idx1 = 0;
            }
            if(char_idx2 >= word2[str_idx2].size()){
                str_idx2++;
                char_idx2 = 0;
            }
        }
        return true;
    }
};
// @lc code=end

