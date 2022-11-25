#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  inline int binarySize(int n){
    return (32 - __builtin_clz(n));
  }

  int concatenatedBinary(int n) {
    // ab (mod n) = [a (mod n) x b (mod n)] (mod n)

    const int modulo = 1000000007;

    uint64_t offset = 1;
    uint64_t total = 0;
    for(int i = n; i >= 1; --i){
      uint64_t mul = i*offset;
      total += mul%modulo;

      // shift offset
      int offset_size = binarySize(i);
      for(int k = 0; k < offset_size; ++k){
        offset <<= 1;
        if(offset >= modulo){
          offset %= modulo;
        }
      }
    }

    // mod
    total %= modulo;
    return total;
  }
};

int main(){

  Solution s;
  cerr << s.concatenatedBinary(9374);

  return 0;
}