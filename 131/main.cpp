/*
 * @lc app=leetcode id=131 lang=cpp
 *
 * [131] Palindrome Partitioning
 */

#include <vector>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<string>> ans;

    void helper(string &s, int idx, vector<string> &vec){
        if(idx == s.size()){
            ans.emplace_back(vec);
        }
        for(int i = idx; i < s.size(); ++i){
            bool valid = true;
            int front = idx, back = i;
            while(front < back && valid){
                if(s[front] != s[back]) valid = false;
                front++;
                back--;
            }
            if(valid){
                vec.emplace_back(string(s.begin()+idx, s.begin()+i+1));
                helper(s, i+1, vec);
                vec.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string> vec;
        helper(s, 0, vec);
        return ans;
    }
};
// @lc code=end

