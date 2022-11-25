#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
  int findCircleNum(vector<vector<int>>& isConnected) {
    stack<int> s;
    int visitCount = isConnected.size();
    vector<bool> visited(isConnected.size(), false);

    int province = 0;
    while(visitCount > 0){
      for(int i = 0; i < isConnected.size(); ++i){
        if(visited[i] == false){
          s.push(i);
          break;
        }
      }
      province++;
      while(!s.empty()){
        int city = s.top(); s.pop();
        if(visited[city]) continue;
        visited[city] = true;
        visitCount--;
        for(int i = 0; i < isConnected.size(); ++i){
          if(isConnected[city][i] == 1){
            s.push(i);
          }
        }
      }
    }

    return province;
  }
};

int main(){
  return 0;
}