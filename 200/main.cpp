#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct COORD{
  int x, y;
  int dir;
  COORD(int _x, int _y, int _dir): x(_x), y(_y), dir(_dir) {}
};

class Solution {
public:
  int numIslands(vector<vector<char>> grid) {
    int count = 0;
    int x_offset[4] = {1,0,-1,0};
    int y_offset[4] = {0,1,0,-1};
    for(int i = 0; i < grid.size(); i++){
      for(int j = 0; j < grid.front().size(); j++){
        if(grid[i][j] == '1'){
          count++;
          // DFS on i, j
          stack<COORD> s;
          s.push(COORD(i, j, 0));
          while(!s.empty()){
            COORD &coord = s.top(); 
            grid[coord.x][coord.y] = '0';
            if(coord.dir < 4){
              int x = coord.x + x_offset[coord.dir];
              int y = coord.y + y_offset[coord.dir];
              if(x >= 0 && x < grid.size() && y >= 0 && y < grid.front().size()){
                if(grid[x][y] == '1'){
                  s.push(COORD(x, y, 0));
                }
              }
              coord.dir++;
            }else{
              s.pop();
            }
          }
        }
      }
    }
    return count;
  }
};

int main(){
  return 0;
}