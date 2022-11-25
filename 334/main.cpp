#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
  bool increasingTriplet(vector<int>& nums) {
    int val1 = nums[0], val2 = INT_MAX;
    for(int i = 1; i < nums.size(); ++i){
      if(nums[i] > val2){
        return true;
      }else if(nums[i] < val2 && nums[i] > val1){
        val2 = nums[i];
      }else if(nums[i] < val1){
        val1 = nums[i];
      }
    }
    return false;
  }
};

int main(){
  return 0;
}