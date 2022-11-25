/*
 * @lc app=leetcode id=1466 lang=cpp
 *
 * [1466] Reorder Routes to Make All Paths Lead to the City Zero
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int DFS(vector<vector<int>>& connections, vector<bool> &visit, int n, int now){
        visit[now] = true;
        int wrong = 0;
        for(int c : connections[now]){
            if(c >= 0){ // wrong direction
                if(visit[c]) continue;
                wrong += 1;
                wrong += DFS(connections, visit, n, c);
            }else{
                if(visit[c+n]) continue;
                wrong += DFS(connections, visit, n, c + n);
            }
        }
        return wrong;
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> matrix(n);
        for(auto conn : connections){
            matrix[conn[0]].push_back(conn[1]);
            matrix[conn[1]].push_back(conn[0] - n);
        }
        vector<bool> visit(n, false);
        return DFS(matrix, visit, n, 0);
    }
};
// @lc code=end

