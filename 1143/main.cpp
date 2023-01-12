/*
 * @lc app=leetcode id=1143 lang=cpp
 *
 * [1143] Longest Common Subsequence
 */

#include <vector>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:

    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> table(text1.size()+1, vector<int>(text2.size()+1, 0));
        
        for(int i = 0; i <= text1.size(); ++i){
            table[i][0] = 0;
        }
        for(int i = 0; i <= text2.size(); ++i){
            table[0][i] = 0;
        }

        for(int i = 1; i <= text1.size(); ++i){
            for(int j = 1; j <= text2.size(); ++j){
                if(text1[i-1] == text2[j-1]){
                    table[i][j] = table[i-1][j-1] + 1;
                }else{
                    table[i][j] = max(table[i-1][j], table[i][j-1]);
                }
            }
        }

        return table[text1.size()][text2.size()];
    }
};
// @lc code=end

