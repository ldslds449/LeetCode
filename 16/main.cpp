#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> findOriginalArray(vector<int>& changed) {
    vector<int> hash(100001, 0);
    for(int i = 0; i < changed.size(); ++i){
      hash[changed[i]]++;
    }

    vector<int> r;

    // zero
    if(hash[0] > 0){
      if(hash[0] & 1 == 1){
        return vector<int>();
      }else{
        for(int i = 0; i < (hash[0] >> 1); ++i){
          r.push_back(0);
        }
      }
    }

    for(int i = 1; i < 100001; ++i){
      int num = hash[i];
      if(num > 0){
        if(i > 50000){
          return vector<int>(); 
        }else{
          for(int k = 0; k < num; ++k){
            r.push_back(i);
            hash[i]--;
          }
          hash[i<<1] -= num;
          if(hash[i<<1] < 0){
            return vector<int>();
          }
        }
      }
    }

    return r;
  }
};

int main(){
  return 0;
}