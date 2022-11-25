/*
 * @lc app=leetcode id=587 lang=cpp
 *
 * [587] Erect the Fence
 */

#include <vector>
#include <algorithm>

using namespace std;

#define X 0
#define Y 1

// @lc code=start
class Solution {
public:

    // ab ac
    int area(vector<int> &a, vector<int> &b, vector<int> &c){
        int vector_ab_x = b[X] - a[X];
        int vector_ab_y = b[Y] - a[Y];
        int vector_ac_x = c[X] - a[X];
        int vector_ac_y = c[Y] - a[Y];

        return vector_ab_x*vector_ac_y - vector_ab_y*vector_ac_x;
    }

    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        if(trees.size() <= 3) return trees;
        vector<vector<int>> result;

        sort(trees.begin(), trees.end(), [](auto &a, auto &b)->bool{
            return a[X] < b[X] || (a[X] == b[X] && a[Y] < b[Y]);
        });

        // lower
        for(int i = 0; i < trees.size(); ++i){
            while(result.size() >= 2 && area(result[result.size()-2], result[result.size()-1], trees[i]) < 0){
                result.pop_back();
            }
            result.push_back(trees[i]);
        }

        if(trees.size() == result.size()) return result;

        // upper
        int size = result.size();
        for(int i = trees.size()-1-1; i >= 0; --i){
            while(result.size()-size >= 1 && area(result[result.size()-2], result[result.size()-1], trees[i]) < 0){
                result.pop_back();
            }
            result.push_back(trees[i]);
        }
        result.pop_back();
        return result;
    }
};
// @lc code=end

