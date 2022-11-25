#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct COORD{
  int x, y;
  COORD(int _x, int _y): x(_x), y(_y) {}
};

class Solution {
public:

  int maxDistance(vector<vector<int>>& grid) {
    int h = grid.size();
    int w = grid[0].size();

    queue<COORD> q1, q2;
    queue<COORD> *now_q = &q1, *add_q = &q2;

    int water_count = 0;
    for(int i = 0; i < h; ++i){
      for(int k = 0; k < w; ++k){
        if(grid[i][k] == 1){
          now_q->push(COORD(i+1, k));
          now_q->push(COORD(i, k-1));
          now_q->push(COORD(i-1, k));
          now_q->push(COORD(i, k+1));
        }
      }
    }
    if(now_q->size() == 0 || w*h == (now_q->size() >> 2)) return -1;

    int dist = 0;
    do{
      while(!now_q->empty()){
        auto coord = now_q->front(); now_q->pop();
        if(coord.x < 0 || coord.x >= h || coord.y < 0 || coord.y >= w) continue; // out of grid
        if(grid[coord.x][coord.y] == 1) continue;
        grid[coord.x][coord.y] = 1; // prevent from loop
        add_q->push(COORD(coord.x+1, coord.y));
        add_q->push(COORD(coord.x, coord.y-1));
        add_q->push(COORD(coord.x-1, coord.y));
        add_q->push(COORD(coord.x, coord.y+1));
      }
      swap(now_q, add_q);
      dist++;
    }while(!now_q->empty());

    return dist-1;
  }
};

int main(){
  return 0;
}