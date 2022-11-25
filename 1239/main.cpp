/*
 * @lc app=leetcode id=1239 lang=cpp
 *
 * [1239] Maximum Length of a Concatenated String with Unique Characters
 */

#include <vector>
#include <string>

using namespace std;

// @lc code=start
#define ENCODE(c) ((int)1 << (c-'a'))
#define LEN(x) (__builtin_popcount(x))

class Solution {
public:
    int max_len = 0;

    void helper(vector<int> &encode, int start, int now){
        if(start < 0){
            if(LEN(now) > max_len){
                max_len = LEN(now);
            }
            return;
        }

        for(int i = start-1; i >= 0; --i){
            if(encode[i] == -1) continue;
            if(!(now & encode[i])){
                helper(encode, i, now | encode[i]);
            }
        }
        helper(encode, -1, now);

        return;
    }

    int maxLength(vector<string>& arr) {
        vector<int> encode(arr.size(), 0);
        for(int i = 0; i < arr.size(); ++i){
            for(int k = 0; k < arr[i].size(); ++k){
                encode[i] |= ENCODE(arr[i][k]);
            }
            if(LEN(encode[i]) != arr[i].size()){
                encode[i] = -1;
            }
        }
        encode.push_back(0);

        helper(encode, arr.size(), 0);
        return max_len;
    }
};
// @lc code=end

