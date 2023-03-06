/*
 * @lc app=leetcode id=953 lang=cpp
 *
 * [953] Verifying an Alien Dictionary
 */

#include <vector>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> weight(26);
        for(int i = 0; i < 26; ++i){
            weight[order[i]-'a'] = i;
        } 

        for(int i = 1; i < words.size(); ++i){
            int size = max(words[i-1].size(), words[i].size());
            int k = 0, w1, w2;
            do{
                w1 = k < words[i-1].size() ? weight[words[i-1][k]-'a'] : -1;
                w2 = k < words[i].size() ? weight[words[i][k]-'a'] : -1;
                if(w1 > w2) return false;
                k++;
            }while(w1 == w2 && k < size);
        }

        return true;
    }
};
// @lc code=end

