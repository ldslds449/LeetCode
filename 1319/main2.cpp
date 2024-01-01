#include <vector>

using namespace std;

class Solution {
public:

  void dfs(int node, vector<vector<int>> &adj, vector<bool> &visit){
    visit[node] = true;
    for(int &c: adj[node]){
      if(visit[c]) continue;
      dfs(c, adj, visit);
    }
  }

  int makeConnected(int n, vector<vector<int>>& connections) {
    if(connections.size() < n-1) return -1;

    vector<vector<int>> adj(n);
    for(auto &c : connections){
      adj[c[0]].push_back(c[1]);
      adj[c[1]].push_back(c[0]);
    }

    int count = 0;
    vector<bool> visit(n, false);
    for(int i = 0; i < n; ++i){
      if(visit[i]) continue;
      count++;
      dfs(i, adj, visit);
    }

    return count-1;
  }
};