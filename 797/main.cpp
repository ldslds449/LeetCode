#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> result;

  void DFS(vector<vector<int>>& graph, int now, vector<int> path){
    path.push_back(now);

    if(now == graph.size()-1){
      result.push_back(path);
    }

    for(auto c : graph[now]){
      DFS(graph, c, path);
    }
  }

  vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    DFS(graph, 0, {});
    return result;
  }
};

int main(){
  return 0;
}