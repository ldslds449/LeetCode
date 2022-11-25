/*
 * @lc app=leetcode id=433 lang=cpp
 *
 * [433] Minimum Genetic Mutation
 */

#include <string>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

// @lc code=start
class Solution {
public:
    bool canMutate(string a, string b){
        int diff = 0;
        for(int i = 0; i < a.size(); ++i){
            if(a[i] != b[i]) diff++;
        }
        return diff == 1;
    }

    int minMutation(string start, string end, vector<string>& bank) {
        queue<string> q;
        q.push(start);
        unordered_set<string> visit;
        char Case[4] = {'A', 'C', 'G', 'T'};
        int diff = 0;
        while(!q.empty()){
            int qSize = q.size();
            for(int i = 0; i < qSize; ++i){
                string now = q.front(); q.pop();
                if(now == end) return diff;
                visit.insert(now);
                for(int k = 0; k < bank.size(); ++k){
                    if(visit.count(bank[k]) == 0 && canMutate(bank[k], now)){
                        q.push(bank[k]);
                    }
                }
            }
            diff++;
        }
        return -1;
    }
};
// @lc code=end

