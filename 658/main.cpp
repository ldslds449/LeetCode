#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

#define START 0
#define END 1
#define HEIGHT 2

struct Point{
  int end;
  int value;
  Point(int _end, int _value): end(_end), value(_value){}
};

struct cmp_height{
  bool operator()(const Point &a, const Point &b){
    return a.value < b.value;
  }
};

struct cmp_end{
  bool operator()(const Point &a, const Point &b){
    return a.end > b.end;
  }
};

class Solution {
public:
  vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
    priority_queue<Point,vector<Point>,cmp_height> height_q;
    priority_queue<Point,vector<Point>,cmp_end> end_q;;
    
    int now_height = 0, now_x = 0;
    int idx = 0;
    vector<vector<int>> result;

    while(idx < buildings.size() || end_q.size() > 0){

      if(idx >= buildings.size() || // no more buildings
        (end_q.size() > 0 && end_q.top().end < buildings[idx][START])){ // (up -> down) / flat
        now_x = end_q.top().end;

        while(height_q.size() > 0 && height_q.top().end <= now_x){ height_q.pop(); } // remove

        if(height_q.size() <= 0){
          now_height = 0;
          // record
          result.push_back({now_x, now_height});
        }else if(now_height > height_q.top().value){
          now_height = height_q.top().value;
          // record
          result.push_back({now_x, now_height});
        }

        end_q.pop();

        while(end_q.size() > 0 && end_q.top().end == now_x){ end_q.pop(); } // remove
      }else if(end_q.size() <= 0 || end_q.top().end > buildings[idx][START]){ // (down -> up) / flat
        int height = buildings[idx][HEIGHT];
        end_q.push(Point(buildings[idx][END], buildings[idx][HEIGHT]));
        height_q.push(Point(buildings[idx][END], buildings[idx][HEIGHT]));
        // peek
        while(idx+1 < buildings.size() && buildings[idx][START] == buildings[idx+1][START]){
          height = max(height, buildings[idx+1][HEIGHT]);
          end_q.push(Point(buildings[idx+1][END], buildings[idx+1][HEIGHT]));
          height_q.push(Point(buildings[idx+1][END], buildings[idx+1][HEIGHT]));
          idx++;
        }
        now_x = buildings[idx][START];

        if(now_height < height){
          now_height = height;
          // record
          result.push_back({now_x, now_height});
        }

        idx++;
      }else{ // both / flat
        now_x = end_q.top().end;
        while(height_q.size() > 0 && height_q.top().end <= now_x){ height_q.pop(); } // remove
        // peek
        int height = max(buildings[idx][HEIGHT], (height_q.size() == 0 ? 0 : height_q.top().value));
        end_q.push(Point(buildings[idx][END], buildings[idx][HEIGHT]));
        height_q.push(Point(buildings[idx][END], buildings[idx][HEIGHT]));
        while(idx+1 < buildings.size() && buildings[idx][START] == buildings[idx+1][START]){
          height = max(height, buildings[idx+1][HEIGHT]);
          end_q.push(Point(buildings[idx+1][END], buildings[idx+1][HEIGHT]));
          height_q.push(Point(buildings[idx+1][END], buildings[idx+1][HEIGHT]));
          idx++;
        }

        if(height > now_height || height < now_height){
          now_height = height;
          // record
          result.push_back({now_x, now_height});
        }
        
        idx++;
        end_q.pop();
        while(end_q.size() > 0 && end_q.top().end == now_x){ end_q.pop(); } // remove
      }
    }
    return result;
  }
};

int main(){
  vector<vector<int>> input{{1,2,3}};
  for(auto ii : input){
    for(auto iii : ii){
      cerr << iii << " ";
    } cerr << "\n";
  }
  Solution s;
  auto r = s.getSkyline(input);
  for(auto rr : r){
    cerr << "[" << rr[0] << "," << rr[1] << "] ";
  } cerr << "\n";

  return 0;
}