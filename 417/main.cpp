#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

class Solution {
public:
  void BFS(vector<vector<int>>& heights, vector<vector<bool>>& result, queue<pair<int,int>> &q, int m, int n){
    while(!q.empty()){
      auto now = q.front(); q.pop();
      if(now.first < 0 || now.first >= m || now.second < 0 || now.second >= n) continue;
      if(result[now.first][now.second] == true) continue;
      result[now.first][now.second] = true;
      int x = now.first, y = now.second;
      if(x+1 < m && heights[x][y] <= heights[x+1][y]) q.push({x+1, y});
      if(y-1 >= 0 && heights[x][y] <= heights[x][y-1]) q.push({x, y-1});
      if(x-1 >= 0 && heights[x][y] <= heights[x-1][y]) q.push({x-1, y});
      if(y+1 < n && heights[x][y] <= heights[x][y+1]) q.push({x, y+1});
    }
  }

  vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    int m = heights.size();
    int n = heights.front().size();

    auto result1 = vector<vector<bool>>(m,vector<bool>(n,false));
    auto result2 = result1;
    queue<pair<int,int>> q;
    // Pacific Ocean
    for(int i = 0; i < m; ++i) q.push({i, 0});
    for(int j = 0; j < n; ++j) q.push({0, j});
    BFS(heights, result1, q, m, n);
    // Atlantic Ocean
    for(int i = 0; i < m; ++i) q.push({i, n-1});
    for(int j = 0; j < n; ++j) q.push({m-1, j});
    BFS(heights, result2, q, m, n);
    // result
    vector<vector<int>> r;
    for(int i = 0; i < m; ++i){
      for(int j = 0; j < n; ++j){
        if(result1[i][j] && result2[i][j]){
          r.push_back({i, j});
        }
      }
    }
    return r;
  }
};

int main(){
  return 0;
}