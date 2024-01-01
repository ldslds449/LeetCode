/*
 * @lc app=leetcode id=1405 lang=cpp
 *
 * [1405] Longest Happy String
 */

#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string ans = "";

        int tmp[3] = {a, b, c};
        string str[] = {"a", "b", "c"};
        while(true){
            int first = 0;
            for(int i = 0; i < 3; ++i){
                if(tmp[i] > tmp[first]) first = i;
            }
            int second = (first+1)%3;
            for(int i = 0; i < 3; ++i){
                if(i == first) continue;
                if(tmp[i] > tmp[second]) second = i;
            }
            
            for(int i = 0; i < min(tmp[first], 2); ++i){
                ans += str[first];
                tmp[first] --;
            }
            if(tmp[second] == 0) break;
            if(tmp[first] >= tmp[second]){
                ans += str[second];
                tmp[second] --;
            }
        }

        return ans;
    }
};
// @lc code=end

