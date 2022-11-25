#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int area(vector<vector<int>>& grid, int x, int y){
    if(x < 0 || x >= grid.size()) return 0;
    if(y < 0 || y >= grid[0].size()) return 0;
    int total = 0;
    if(grid[x][y] == 1){
      grid[x][y] = 0;
      total += 1;
      total += area(grid, x+1, y);
      total += area(grid, x, y-1);
      total += area(grid, x-1, y);
      total += area(grid, x, y+1);
    }
    return total;
  }
  int maxAreaOfIsland(vector<vector<int>>& grid) {
    int max_value = 0;
    for(int i = 0; i < grid.size(); ++i){
      for(int k = 0; k < grid.front().size(); ++k){
        if(grid[i][k] == 1){
          max_value = max(max_value, area(grid, i, k));
        }
      }
    }
    return max_value;
  }
};

int main(){
  return 0;
}