#include <iostream>
#include <vector>
#include <utility>
#include <stack>

using namespace std;

class Solution {
public:
  bool canVisitAllRooms(vector<vector<int>>& rooms) {
    stack<pair<int,int>> s;

    int count = 0;
    vector<bool> visited(rooms.size(), false);
    
    s.push({0, 0}); 
    while(!s.empty()){
      auto &p = s.top();

      if(p.second == 0){
        if(visited[p.first]){
          s.pop();
          continue;
        }
        count++;
        if(count == rooms.size()) return true;
        visited[p.first] = true;
      }

      if(p.second >= rooms[p.first].size()){
        s.pop();
      }else{
        s.push({rooms[p.first][p.second], 0});
        p.second = p.second+1;
      }
    }
    return false;
  }
};

int main(){
  return 0;
}