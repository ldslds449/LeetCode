#include <vector>

using namespace std;

class Solution {
public:
  int dist = 0x7fffffff;

  void dfs(int node, vector<vector<vector<int>>>& adj, vector<bool> &visit){
    visit[node] = true;
    for(auto child : adj[node]){
      dist = min(dist, child[1]);
      if(visit[child[0]]) continue;
      dfs(child[0], adj, visit);
    }
  }

  int minScore(int n, vector<vector<int>>& roads) {
    vector<vector<vector<int>>> adj(n);
    for(auto &arr : roads){
      adj[arr[0]-1].push_back({arr[1]-1, arr[2]});
      adj[arr[1]-1].push_back({arr[0]-1, arr[2]});
    }

    vector<bool> visit(n, false);
    dfs(n-1, adj, visit);
    return dist;
  }
};