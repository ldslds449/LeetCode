/*
 * @lc app=leetcode id=790 lang=cpp
 *
 * [790] Domino and Tromino Tiling
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int numTilings(int n) {
        if(n == 1) return 1;
        vector<int> flat(n, 0), top(n, 0), down(n, 0);
        flat[0] = 1; flat[1] = 2;
        top[1] = 1; down[1] = 1;
        for(int i = 2; i < n; ++i){
            flat[i] = ((long long)flat[i-1] + flat[i-2]) % (int)(1e9+7);
            flat[i] = ((long long)flat[i] + top[i-1] + down[i-1]) % (int)(1e9+7);
            top[i] = ((long long)flat[i-2] + down[i-1]) % (int)(1e9+7);
            down[i] = ((long long)flat[i-2] + top[i-1]) % (int)(1e9+7);
        }
        return flat[n-1];
    }
};
// @lc code=end

