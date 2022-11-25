#include <iostream>
#include <array>
#include <vector>

using namespace std;

class Solution {
public:
  bool surround(vector<vector<int>>& grid, int x, int y){
    if(x < 0 || x >= grid.size()) return false;
    if(y < 0 || y >= grid[0].size()) return false;
    if(grid[x][y] == 0){
      grid[x][y] = 1;
      bool r1 = surround(grid, x+1, y);
      bool r2 = surround(grid, x, y-1);
      bool r3 = surround(grid, x-1, y);
      bool r4 = surround(grid, x, y+1);
      return r1 && r2 && r3 && r4;
        ;
    }
    return true;
  }

  int closedIsland(vector<vector<int>>& grid) {
    int count = 0;
    for(int i = 0; i < grid.size(); ++i){
      for(int k = 0; k < grid[0].size(); ++k){
        if(grid[i][k] == 0){
          count += surround(grid, i, k);
        }
      }
    }
    return count;
  }
};

int main(){
  return 0;
}