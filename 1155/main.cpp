#include <iostream>
#include <vector>

using namespace std;

const int mod = 1e9+7;

class Solution {
public:

  int table[31][1001]; // dice number, target

  int numRollsToTarget(int n, int k, int target) {
    table[0][0] = 1;
    for(int i = 1; i <= target; ++i){ table[0][i] = 0; }
    for(int i = 1; i <= n; ++i){ table[i][0] = 0; }
    for(int j = 1; j <= n; ++j){
      for(int i = 1; i <= target; ++i){
        table[j][i] = 0;
        for(int h = 1; h <= k; ++h){
          if(i-h >= 0){
            table[j][i] = ((int64_t)table[j][i] + table[j-1][i-h]) % mod;
          }
        }
      }
    }
    return table[n][target];
  }
};

int main(){
  Solution s;
  cerr << s.numRollsToTarget(30, 30, 500);
  return 0;
}