/*
 * @lc app=leetcode id=520 lang=cpp
 *
 * [520] Detect Capital
 */

#include <string>
#include <cctype>
#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    bool detectCapitalUse(string word) {
        bool firstCaptical = isupper(word[0]);
        int hasUpper = -1;
        for(int i = 1; i < word.size(); ++i){
            if(!firstCaptical){
                if(isupper(word[i])) return false;
            }else{
                if(hasUpper == -1) hasUpper = (bool)isupper(word[i]);
                else if(!(hasUpper ^ (bool)islower(word[i]))) return false;
            }
        }
        return true;
    }
};
// @lc code=end


int main(){
    Solution s;
    s.detectCapitalUse("FFFFFFFFFFFf");
}
