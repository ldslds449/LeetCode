/*
 * @lc app=leetcode id=802 lang=cpp
 *
 * [802] Find Eventual Safe States
 */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        stack<int> s;
        vector<bool> visit(graph.size()+1, false);
        vector<bool> ing(graph.size()+1, false);
        vector<bool> safe(graph.size()+1, true);

        for(int i = 1; i <= graph.size(); ++i){
            if(visit[i] == false){
                s.push(i);
                while(!s.empty()){
                    int now = s.top(); s.pop();
                    if(now < 0){
                        ing[-now] = false;
                        continue;
                    }
                    if(ing[now] || !safe[now]){
                        while(!s.empty()){
                            int del = s.top(); s.pop();
                            if(del < 0){
                                safe[-del] = false;
                                ing[-del] = false;
                            }
                        }
                        continue;
                    }
                    if(visit[now]) continue;
                    visit[now] = true;
                    ing[now] = true;
                    s.push(-now); // cancel ing
                    for(int c : graph[now-1]){
                        s.push(c+1);
                    }
                }
            }
        }

        vector<int> result;
        for(int i = 1; i <= graph.size(); ++i){
            if(safe[i]){
                result.push_back(i-1);
            }
        }

        return result;
    }
};
// @lc code=end


int main(){
    Solution s;
    vector<vector<int>> vec{{1,2},{2,3},{5},{0},{5},{},{}};
    s.eventualSafeNodes(vec);
}
