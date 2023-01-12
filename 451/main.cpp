/*
 * @lc app=leetcode id=451 lang=cpp
 *
 * [451] Sort Characters By Frequency
 */

#include <string>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:

    string frequencySort(string s) {
        vector<int> freq(26*2+10, 0);
        for(char c : s){
            int code;
            if(c >= '0' && c <= '9'){
                code = 52 + c - '0';
            }else{
                code = c - (c >= 'a' && c <= 'z' ? 'a' : ('A'-26));
            }
            freq[code]++;
        }

        vector<int> rank(26*2+10);
        iota(rank.begin(), rank.end(), 0);
        sort(rank.begin(), rank.end(), [&](const int a, const int b)->bool{
            return freq[a] > freq[b];
        });

        int idx = 0;
        for(int i = 0; i < 26*2+10; ++i){
            if(freq[rank[i]] == 0) break;
            char c;
            if(rank[i] >= 52){
                c = rank[i] - 52 + '0';
            }else{
                c = (rank[i] >= 26 ? ('A'-26) : 'a') + rank[i];
            }
            for(int k = 0; k < freq[rank[i]]; ++k){
                s[idx++] = c;
            }
        }
        return s;
    }
};
// @lc code=end

