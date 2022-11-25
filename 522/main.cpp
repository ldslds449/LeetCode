/*
 * @lc app=leetcode id=522 lang=cpp
 *
 * [522] Longest Uncommon Subsequence II
 */

#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    // return a belongs to b
    bool subSeq(string &a, string &b){
        if(a.size() > b.size()) return false;
        int a_idx = 0, b_idx = 0;
        while(a_idx < a.size() && b_idx < b.size()){
            if(a[a_idx] == b[b_idx]) a_idx++;
            b_idx++;
        }
        return a_idx == a.size();
    }

    int findLUSlength(vector<string>& strs) {
        int max_val = -1;
        for(int i = 0; i < strs.size(); ++i){
            bool pass = true;
            for(int k = 0; k < strs.size(); ++k){
                if(i == k) continue;
                if(subSeq(strs[i], strs[k])){
                    pass = false; break;
                }
            }
            if(pass) max_val = max(max_val, (int)strs[i].size());
        }
        return max_val;
    }
};
// @lc code=end

