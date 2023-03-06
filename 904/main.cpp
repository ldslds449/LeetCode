/*
 * @lc app=leetcode id=904 lang=cpp
 *
 * [904] Fruit Into Baskets
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int t1 = fruits[0], idx1 = 0;
        int t2 = -1, idx2 = 999999;

        int count = 1, max_count = 1;
        for(int i = 1; i < fruits.size(); ++i){
            if(fruits[i] == t1){
                idx1 = i;
                count++;
                if(idx1 > idx2){
                    swap(t1, t2);
                    swap(idx1, idx2);
                }
            }else if(t2 == -1){
                t2 = fruits[i];
                idx2 = i;
                count++;
            }else if(fruits[i] == t2){
                idx2 = i;
                count++;
            }else{
                count = i - idx1;
                t1 = fruits[i];
                idx1 = i;
                swap(t1, t2);
                swap(idx1, idx2);
            }
            max_count = max(max_count, count);
        }

        return max_count;
    }
};
// @lc code=end

