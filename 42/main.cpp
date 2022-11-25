#include <array>
#include <vector>
#include <iostream>

using namespace std;


class Solution {
public:
    array<int, 20001> list;
  
    int trap(vector<int> height) {
      // initial
      for(int i = 0; i < height.size(); ++i){
        list[i] = 0;
      }
      
      // left
      int precent_max = -1;  
      for(int i = 0; i < height.size(); ++i){
        int &now = height[i];
        list[i] = (now < precent_max ? precent_max : now);
        precent_max = max(now, precent_max);
      }
      
      // right
      precent_max = -1;
      for(int i = height.size()-1; i >= 0; i--){
        int &now = height[i];
        list[i] = min(list[i], (now < precent_max ? precent_max : now));
        precent_max = max(now, precent_max);
      }
      
      // calculate
      int count = 0;
      for(int i = 0; i < height.size(); ++i){
        count += max((list[i] - height[i]), 0);
      }
      
      return count;
    }
};

int main(){
  Solution s;

  cerr << s.trap({0,1,0,2,1,0,1,3,2,1,2,1});

  return 0;
}