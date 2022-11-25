#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
  int threeSumClosest(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());

    int closest = 99999999;
    int result = nums[0] + nums[1] + nums[2];

    for(int i = 0; i < nums.size()-2; ++i){
      if(nums[i]*3 > target) return closest < abs(target - nums[i] - nums[i+1] - nums[i+2]) ? result : nums[i] + nums[i+1] + nums[i+2];
      int left = i+1, right = nums.size()-1;
      while(left < right){
        int sum = nums[i] + nums[left] + nums[right];
        int diff = abs(target - sum);
        if(diff < closest){
          closest = diff;
          result = sum;
        }
        if(sum > target){
          right--;
        }else{
          left++;
        }
      }
    }

    return result;
  }
};

int main(){
  return 0;
}