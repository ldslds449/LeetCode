#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

class Solution {
public:
  int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
    int m = maze.size();
    int n = maze.front().size();
    queue<pair<int,int>> q;

    q.push({entrance[0], entrance[1]});

    int dist = 0;
    bool found = false;
    for(;; dist++){
      int qsize = q.size();
      for(int i = 0; i < qsize; ++i){
        auto p = q.front(); q.pop();
        if(p.first < 0 || p.second < 0 || p.first >= m || p.second >= n){
          continue;
        }
        if(maze[p.first][p.second] == '+') continue;
        if(p.first == 0 || p.second == 0 || p.first == m-1 || p.second == n-1){
          if(dist > 0){
            found = true;
            break;
          }
        }
        maze[p.first][p.second] = '+';
        q.push({p.first+1, p.second});
        q.push({p.first, p.second-1});
        q.push({p.first-1, p.second});
        q.push({p.first, p.second+1});
      }
      if(found) break;
      if(q.size() == 0) break;
    }

    return found ? dist : -1;
  }
};

int main(){
  return 0;
}