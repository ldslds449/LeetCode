/*
 * @lc app=leetcode id=947 lang=cpp
 *
 * [947] Most Stones Removed with Same Row or Column
 */

#include <vector>
#include <list>
#include <set>
#include <unordered_map>

#define X(n) (n[0])
#define Y(n) (-n[1]-1)

using namespace std;

// @lc code=start
class Solution {
public:
    void dfs(unordered_map<int, list<int>> &graph, set<int> &visit, int now){
        visit.insert(now);
        for(int n : graph[now]){
            if(visit.count(n) == 0){
                dfs(graph, visit, n);
            }
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        unordered_map<int, list<int>> graph;
        for(auto s : stones){
            graph[X(s)].push_back(Y(s));
            graph[Y(s)].push_back(X(s));
        }
        set<int> visit;
        int count = 0;
        for(auto s : stones){
            if(visit.count(X(s)) == 0){
                dfs(graph, visit, X(s));
                count++;
            }
            if(visit.count(Y(s)) == 0){
                dfs(graph, visit, Y(s));
                count++;
            }
        }
        return stones.size() - count;
    }
};
// @lc code=end

