#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

class Solution {
public:
  vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    int x_offset[4] = {1,0,-1,0};
    int y_offset[4] = {0,1,0,-1};
    int target_color = image[sr][sc];
    queue<pair<int,int>> q;
    q.push({sr, sc});
    while(!q.empty()){
      auto p = q.front(); q.pop();
      if(image[p.first][p.second] == color){
        continue;
      }else{
        image[p.first][p.second] = color;
        for(int i = 0; i < 4; ++i){
          int x = p.first + x_offset[i];
          int y = p.second + y_offset[i];
          if(x >= 0 && x < image.size() &&
            y >= 0 && y < image[x].size()){
            if(image[x][y] == target_color){
              q.push({x, y});
            }
          }
        }
      }
    }
    return image;
  }
};

int main(){
  return 0;
}