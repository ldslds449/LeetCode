/*
 * @lc app=leetcode id=381 lang=cpp
 *
 * [381] Insert Delete GetRandom O(1) - Duplicates allowed
 */

#include <vector>
#include <unordered_map>
#include <algorithm>
#include <utility>

using namespace std;

// @lc code=start
class RandomizedCollection {
public:
    RandomizedCollection() {
        srand(time(NULL));
    }
    
    unordered_map<int,vector<int>> table;
    vector<pair<int,int>> array;
    
    bool insert(int val) {
        table[val].push_back(array.size());
        array.push_back({val, table[val].size()-1});
        return table[val].size() == 1;
    }
    
    bool remove(int val) {
        if(table[val].size() == 0) return false;
        int del_idx = table[val].back();
        int swap_idx = array.size()-1;

        table[array[swap_idx].first][array[swap_idx].second] = del_idx;
        swap(array[swap_idx], array[del_idx]);

        table[val].pop_back();
        array.pop_back();

        return true;
    }
    
    int getRandom() {
        int idx = rand() % array.size();
        return array[idx].first;
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
// @lc code=end

