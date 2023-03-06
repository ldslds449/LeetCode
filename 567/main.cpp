/*
 * @lc app=leetcode id=567 lang=cpp
 *
 * [567] Permutation in String
 */

#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;
        
        vector<int> count(26, 0);
        for(char &c : s1) count[c-'a']++;

        for(int i = 0; i < s2.size()-s1.size()+1; ++i){
            if(count[s2[i]-'a']){
                bool found = true;
                vector<int> tmp = count;
                vector<int> prev(26, -1);
                for(int k = i; k < i+s1.size(); k++){
                    int c = s2[k]-'a';
                    if(tmp[c] > 0){
                        tmp[c]--;
                        if(prev[c] == -1) prev[c] = k;
                    }else{
                        if(prev[c] == -1) i = k;
                        else i = prev[c];
                        found = false;
                        break;
                    }
                }
                if(found) return true;

            }
        }
        return false;
    }
};
// @lc code=end

