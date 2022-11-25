#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  string pushDominoes(string dominoes) {
    char prev = ' ';
    unsigned prev_idx = -1;
    for(unsigned i = 0; i <= dominoes.size(); ++i){
      char now = (i == dominoes.size() ? ' ' : dominoes[i]);
      if(now != '.'){
        if(prev != now){
          if(prev == 'L'){ // L...R || L...
            // do not change
          }else if(prev == ' '){ // ...R || ...L
            if(now == 'L'){
              for(unsigned k = prev_idx+1; k < i; ++k){
                dominoes[k] = 'L';
              }
            }
          }else{ // R...L || R...
            if(now == 'L'){
              unsigned time = (i - prev_idx - 1) / 2;
              for(unsigned k = 0; k < time; ++k){
                dominoes[prev_idx+1+k] = 'R';
                dominoes[i-1-k] = 'L';
              }
            }else{
              for(unsigned k = prev_idx+1; k < i; ++k){
                dominoes[k] = 'R';
              }
            }
          }
        }else{ // L...L || R...R || ...
          if(now != ' '){
            for(unsigned k = prev_idx+1; k < i; ++k){
              dominoes[k] = now;
            }
          }
        }
        prev = dominoes[i];
        prev_idx = i;
      }
    }
    return dominoes;
  }
};

int main(){
  return 0;
}