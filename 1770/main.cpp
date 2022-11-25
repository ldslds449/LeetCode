#include <iostream>
#include <array>
#include <vector>

using namespace std;

class Solution {
public:

    array<array<int,1001>,1001> table;

    int maximumScore(vector<int> nums, vector<int> mul) {
      // initial
      table[0][0] = 0;

      // row & col
      for(int i = 1; i <= mul.size(); ++i){
        table[i][0] = table[i-1][0] + mul[i-1]*nums[i-1];
        table[0][i] = table[0][i-1] + mul[i-1]*nums[nums.size()-i];
      }
      
      // other
      for(int i = 1; i <= mul.size(); ++i){
        for(int k = 1; k < i; ++k){
          int start_offset = k;
          int end_offset = i-k;
          int r1 = table[start_offset-1][end_offset];
          int r2 = table[start_offset][end_offset-1];
          int add1 = mul[i-1]*nums[start_offset-1];
          int add2 = mul[i-1]*nums[nums.size()-end_offset];

          table[start_offset][end_offset] = max(r1+add1, r2+add2);
        }
      }

      // find max
      int max_value = table[0][mul.size()];
      for(int k = 0; k <= mul.size(); ++k){
        max_value = max(max_value, table[k][mul.size()-k]);
      }

      return max_value;
    }
};

int main(){
  
  Solution* s = new Solution();
  cerr << s->maximumScore(
    {-854,-941,10,299,995,-346,294,-393,351,-76,210,897,-651,920,624,969,-629,985,-695,236,637,-901,-817,546,-69,192,-377,251,542,-316,-879,-764,-560,927,629,877,42,381,367,-549,602,139,-312,-281,105,690,-376,-705,-906,85,-608,639,752,770,-139,-601,341,61,969,276,176,-715,-545,471,-170,-126,596,-737,130},
    {83,315}
  );

  return 0;
}