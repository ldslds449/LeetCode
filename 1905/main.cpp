#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  bool dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int x, int y){
    if(x < 0 || y < 0 || x >= grid2.size() || y >= grid2.front().size()){
      return true;
    }else if(grid2[x][y] == 0){
      return true;
    }else{
      if(grid1[x][y] != 1){
        return false;
      }else{
        grid2[x][y] = 0;
        bool r1 = dfs(grid1, grid2, x+1, y);
        bool r2 = dfs(grid1, grid2, x, y-1);
        bool r3 = dfs(grid1, grid2, x-1, y);
        bool r4 = dfs(grid1, grid2, x, y+1);
        return r1 && r2 && r3 && r4;
      }
    }
  }

  int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
    int count = 0;
    for(int i = 0; i < grid2.size(); i++){
      for(int k = 0; k < grid2.front().size(); ++k){
        if(grid2[i][k] == 1){
          count += dfs(grid1, grid2, i, k);
        }
      }
    }
    return count;
  }
};

int main(){
  return 0;
}