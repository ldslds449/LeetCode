#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  bool walk(vector<vector<int>>& grid, int x, int y, int &count){
    if(x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size()){
      return true;
    }else if(grid[x][y] == 0){
      return false;
    }
    count++;
    grid[x][y] = 0;
    bool r1 = walk(grid, x+1, y, count);
    bool r2 = walk(grid, x, y-1, count);
    bool r3 = walk(grid, x-1, y, count);
    bool r4 = walk(grid, x, y+1, count);
    return r1 || r2 || r3 || r4;
  }

  int numEnclaves(vector<vector<int>>& grid) {
    int total = 0;
    for(int i = 0; i < grid.size(); ++i){
      for(int k = 0; k < grid[0].size(); ++k){
        if(grid[i][k] == 1){
          int count = 0;
          if(!walk(grid, i, k, count)){
            total += count;
          }
        }
      }
    }
    return total;
  }
};

int main(){
  return 0;
}