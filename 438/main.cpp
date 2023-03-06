/*
 * @lc app=leetcode id=438 lang=cpp
 *
 * [438] Find All Anagrams in a String
 */

#include <vector>
#include <string>
#include <queue>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> count(26, 0);
        for(char &c : p) count[c-'a']++;

        vector<int> ans;

        int idx = 0, total = 0;
        vector<queue<int>> prev(26);
        while(idx < s.size()){
            int c = s[idx]-'a';
            if(count[c]){
                count[c]--;
                total++;
                prev[c].push(idx);
                if(total == p.size()){
                    ans.push_back(idx-p.size()+1);
                    total--;
                    count[s[idx-p.size()+1]-'a']++;
                    prev[s[idx-p.size()+1]-'a'].pop();
                }
            }else{
                if(prev[c].size() == 0){
                    for(int i = 0; i < total; ++i){
                        count[s[idx-1-i]-'a']++;
                        prev[s[idx-1-i]-'a'].pop();
                    }
                    total = 0;
                }else{
                    int target = prev[c].front();
                    for(int i = idx-total; i <= target; ++i){
                        count[s[i]-'a']++;
                        prev[s[i]-'a'].pop();
                        total--;
                    }
                    count[c]--;
                    prev[c].push(idx);
                    total++;
                }
            }
            idx++;
        }

        return ans;
    }
};
// @lc code=end

