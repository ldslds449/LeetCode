#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

class Solution {
public:
  int shortestBridge(vector<vector<int>> grid) {
    int n = grid.size();
    queue<pair<int,int>> q, q1;

    // find island
    for(int i = 0; i < n; ++i){
      for(int k = 0; k < n; ++k){
        if(grid[i][k] == 1){
          q.push({i, k});
          while(!q.empty()){
            auto p = q.front(); q.pop();
            if(p.first < 0 || p.second < 0 || p.first >= n || p.second >= n) continue;
            if(grid[p.first][p.second] == 2) continue;
            if(grid[p.first][p.second] == 0){
              q1.push({p.first, p.second});
              continue;
            }
            grid[p.first][p.second] = 2;
            q.push({p.first+1, p.second});
            q.push({p.first, p.second-1});
            q.push({p.first-1, p.second});
            q.push({p.first, p.second+1});
          }
          break;
        }
      }
      if(q1.size() > 0) break;
    }

    int dist = 0;
    for(;; dist++){
      int qsize = q1.size();
      bool found = false;
      for(int i = 0; i < qsize; ++i){
        auto p = q1.front(); q1.pop();
        if(p.first < 0 || p.second < 0 || p.first >= n || p.second >= n) continue;
        if(grid[p.first][p.second] == 2) continue;
        if(grid[p.first][p.second] == 1){
          found = true;
          break;
        }
        grid[p.first][p.second] = 2;
        q1.push({p.first+1, p.second});
        q1.push({p.first, p.second-1});
        q1.push({p.first-1, p.second});
        q1.push({p.first, p.second+1});
      }
      if(found) break;
    }

    return dist;
  }
};

int main(){
  Solution s;
  s.shortestBridge({{0,1},{1,0}});
  return 0;
}