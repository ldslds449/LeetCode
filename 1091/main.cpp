#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

class Solution {
public:
  int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    int n = grid.size();
    int length = 0;
    bool found = false;

    queue<pair<int,int>> q;
    q.push({0, 0});
    while(true){
      length++;
      int size = q.size();
      while(size-- > 0){
        auto p = q.front(); q.pop();
        if(p.first < 0 || p.second < 0 || p.first >= n || p.second >= n) continue;
        if(grid[p.first][p.second] == 1) continue;
        if(p.first == n-1 && p.second == n-1) {found = true; break;} // found
        grid[p.first][p.second] = 1;
        q.push({p.first+1, p.second+1});
        q.push({p.first+1, p.second});
        q.push({p.first+1, p.second-1});
        q.push({p.first, p.second+1});
        q.push({p.first, p.second-1});
        q.push({p.first-1, p.second+1});
        q.push({p.first-1, p.second});
        q.push({p.first-1, p.second-1});
      }
      if(q.size() == 0) break;
      if(found) break;
    }

    return found ? length : -1;
  }
};

int main(){
  return 0;
}