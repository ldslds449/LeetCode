/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    bool dfs(vector<vector<int>> &graph, vector<bool> &ing, vector<bool> &seen, int now){
        seen[now] = true;
        ing[now] = true;

        for(int c : graph[now]){
            if(!seen[c]){
                bool r = dfs(graph, ing, seen, c);
                if(!r) return false;
            }else if(ing[c]){
                return false;
            }
        }

        ing[now] = false;
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for(auto &p : prerequisites){
            graph[p[1]].push_back(p[0]);
        }

        vector<bool> ing(numCourses), seen(numCourses);
        for(int i = 0; i < numCourses; ++i){
            bool r = dfs(graph, ing, seen, i);
            if(!r) return false;
        }
        return true;
    }
};
// @lc code=end

