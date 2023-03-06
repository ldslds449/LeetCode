#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    struct Info{
      long long count;
      long long fuel;
      Info(long long _c, long long _f): count(_c), fuel(_f){};
    };

    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
      // adj
      vector<vector<int>> adj(roads.size()+1);
      // degree
      vector<int> degree(roads.size()+1, 0);
      for(auto &r : roads){
        adj[r[0]].push_back(r[1]);
        adj[r[1]].push_back(r[0]);
        degree[r[0]]++;
        degree[r[1]]++;
      }

      vector<Info> info(roads.size()+1, Info(1, 0));
      
      queue<int> q;
      for(int i = 1; i < degree.size(); ++i){
        if(degree[i] == 1) q.push(i);
      }

      while(!q.empty()){
        int now = q.front(); q.pop();
        degree[now]--;

        for(int p : adj[now]){
          if(degree[p] == 0) continue;
          degree[p]--;
          if(degree[p] == 1 && p > 0){
            q.push(p);
          }

          info[p].count += info[now].count;
          info[p].fuel += (info[now].count + seats - 1) / seats + info[now].fuel;
          break;
        }
      }

      return info[0].fuel;
    }
};