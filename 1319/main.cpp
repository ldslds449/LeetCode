#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  vector<int> table;

  int findRoot(int idx){
    int now = idx, val = table[idx];
    while(val != now){
      now = val;
      val = table[now];
    }
    table[idx] = val;
    return val;
  }

  int makeConnected(int n, vector<vector<int>>& connections) {
    if(connections.size() < n-1) return -1;
    for(int i = 0; i < n; ++i){
      table.push_back(i);
    }

    for(int i = 0; i < connections.size(); ++i){
      int pc1 = connections[i][0];
      int pc2 = connections[i][1];
      int root1 = findRoot(pc1);
      int root2 = findRoot(pc2);
      if(root1 != root2){
        table[root2] = root1;
      }
    }

    for(int i = 0; i < n-1; ++i){
      findRoot(i);
    }

    sort(table.begin(), table.end());
    int diff = 0;
    for(int i = 0; i < n-1; ++i){
      if(table[i] != table[i+1]){
        diff++;
      }
    }

    return diff+1;
  }
};

int main(){
  return 0;
}