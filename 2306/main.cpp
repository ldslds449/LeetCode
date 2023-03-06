/*
 * @lc app=leetcode id=2306 lang=cpp
 *
 * [2306] Naming a Company
 */

#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

// @lc code=start
class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        vector<unordered_set<string>> arr(26);
        for(auto &str : ideas){
            arr[str[0]-'a'].insert(str.substr(1));
        }

        long long ans = 0;
        for(int i = 0; i < 25; ++i){
            for(int j = i+1; j < 26; ++j){
                int both = 0;
                for(const string &str : arr[i]){
                    if(arr[j].count(str)) both++;
                }
                ans += (arr[i].size() - both) * (arr[j].size() - both);
            }
        }

        return ans << 1;
    }
};
// @lc code=end

