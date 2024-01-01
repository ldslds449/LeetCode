/*
 * @lc app=leetcode id=1218 lang=cpp
 *
 * [1218] Longest Arithmetic Subsequence of Given Difference
 */

#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int> m;
        int max_val = 0;
        for(int i = 0; i < arr.size(); ++i){
            int pre = arr[i] - difference;
            auto it = m.find(pre);
            int val = (it == m.end() ? 0 : it->second) + 1;
            m[arr[i]] = max(m[arr[i]], val);
            max_val = max(max_val, m[arr[i]]);
        }
        return max_val;
    }
};
// @lc code=end

