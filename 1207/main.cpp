/*
 * @lc app=leetcode id=1207 lang=cpp
 *
 * [1207] Unique Number of Occurrences
 */

#include <vector>
#include <unordered_set>

using namespace std;

// @lc code=start
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        vector<int> table(2001, 0);
        for(int n : arr){
            table[n+1000]++;
        }
        unordered_set<int> s;
        for(int i = 0; i < 2001; ++i){
            if(table[i] > 0 && s.count(table[i])) return false;
            s.insert(table[i]);
        }
        return true;
    }
};
// @lc code=end

