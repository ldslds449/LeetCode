/*
 * @lc app=leetcode id=380 lang=cpp
 *
 * [380] Insert Delete GetRandom O(1)
 */

#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// @lc code=start
class RandomizedSet {
public:
    RandomizedSet() {
        srand(time(NULL));
    }

    unordered_map<int,int> table;
    vector<int> array;
    
    bool insert(int val) {
        if(table.count(val)) return false;
        table[val] = array.size();
        array.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if(!table.count(val)) return false;
        table[array[array.size()-1]] = table[val];
        swap(array[array.size()-1], array[table[val]]);
        table.erase(val);
        array.pop_back();
        return true;
    }
    
    int getRandom() {
        int idx = rand() % array.size();
        return array[idx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
// @lc code=end

