#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int minCost(string colors, vector<int>& neededTime) {
    int total = 0, max_value = -1, cost = 0;
    bool isSame = false;
    for(int i = 1; i <= colors.size(); ++i){
      if(i == colors.size() || colors[i] != colors[i-1]){ // not same
        if(isSame){
          cost += total - max_value;
          total = 0;
          max_value = -1;
        }
        isSame = false;
      }else{ // same
        if(!isSame){
          max_value = max(neededTime[i-1], neededTime[i]);
          total += neededTime[i-1] + neededTime[i];
        }else{
          max_value = max(max_value, neededTime[i]);
          total += neededTime[i];
        }
        isSame = true;
      }
    }
    return cost;
  }
};

int main(){
  return 0;
}