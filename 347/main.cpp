/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 */

#include <vector>
#include <map>
#include <numeric>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> freq;
        for(int n : nums) freq[n]++;

        vector<pair<int,int>> rank(freq.begin(), freq.end());
        sort(rank.begin(), rank.end(), [&](auto a, auto b)->bool{
            return a.second > b.second;
        });

        vector<int> r;
        for(int i = 0; i < k; ++i){
            r.emplace_back(rank[i].first);
        }
        return r;
    }
};
// @lc code=end

