/*
 * @lc app=leetcode id=1531 lang=cpp
 *
 * [1531] String Compression II
 */

#include <cstring>
#include <queue>
#include <unordered_set>

using namespace std;

// @lc code=start
class Solution {
public:
    int table[101][101];

    int dfs(string &s, int idx, int k){
        if(idx+k >= s.size()) return 0;
        if(table[idx][k] >= 0) return table[idx][k];

        // delete
        int res = k > 0 ? dfs(s, idx+1, k-1) : 10001;

        int count = 1, new_k = k;
        for(int i = idx+1; i < s.size(); ++i){
            res = min(res, (int)(dfs(s, i, new_k) + (count == 1 ? 0 : to_string(count).size()) + 1));
            if(s[idx] != s[i]){
                new_k--;
                if(new_k < 0) break;
            }else{
                count++;
            }
        }
        if(new_k >= 0){
            res = min(res, (int)((count == 1 ? 0 : to_string(count).size()) + 1));
        }

        table[idx][k] = res;
        return res;
    }

    int getLengthOfOptimalCompression(string s, int k) {
        memset(table, -1, sizeof(int)*101*101);
        return dfs(s, 0, k);
    }
};
// @lc code=end

int main(){
    Solution s;
    string str = "abcdefghijklmnopqrstuvwxyz";
    s.getLengthOfOptimalCompression(str, 16);
    return 0;
}
