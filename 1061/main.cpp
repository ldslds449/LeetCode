#include <string>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:

    int findRoot(vector<int> &parent, int now){
      if(parent[now] == now) return now;
      parent[now] = findRoot(parent, parent[now]);
      return parent[now];
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
      vector<int> parent(26);
      iota(parent.begin(), parent.end(), 0);

      for(int i = 0; i < s1.size(); ++i){
        int c1 = s1[i] - 'a';
        int c2 = s2[i] - 'a';
        int r1 = findRoot(parent, c1);
        int r2 = findRoot(parent, c2);
        
        if(r1 != r2){
          parent[c1] = min(r1, r2);
          parent[c2] = min(r1, r2);
          parent[max(r1, r2)] = min(r1, r2);
        }
      }

      for(char &c : baseStr){
        c = findRoot(parent, c - 'a') + 'a';
      }

      return baseStr;
    }
};