/*
 * @lc app=leetcode id=692 lang=cpp
 *
 * [692] Top K Frequent Words
 */

#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int> m;
        for(auto str : words){
            m[str]++;
        }
        vector<string> strs;
        for(auto p : m){
            strs.push_back(p.first);
        }
        stable_sort(strs.begin(), strs.end(), [&](const string &a, const string &b)->bool{
            return m[a] > m[b];
        });
        return vector<string>(strs.begin(), strs.begin()+k);
    }
};
// @lc code=end

