#include <iostream>
#include <array>
#include <vector>
#include <bitset>

using namespace std;

class Solution {
public:

  vector<int> sumEvenAfterQueries(vector<int> nums, vector<vector<int>>& queries) {
    // sum
    int sum = 0;
    for(int i = 0; i < nums.size(); ++i){
      if((nums[i] & 1) == 0){
        sum += nums[i];
      }
    }

    // calculate
    vector<int> result(queries.size());
    for(int i = 0; i < queries.size(); ++i){
      int val = queries[i][0];
      int index = queries[i][1];
      bool num_even = ((nums[index] & 1) == 0);
      bool val_even = ((val & 1) == 0);
      if(num_even == val_even){ // is even after adding
        sum += (num_even ? val : nums[index] + val);
        result[i] = sum;
      }else{
        if(num_even){
          sum -= nums[index];
        }
        result[i] = sum;
      }
      nums[index] += val;
    }

    return result;
  }
};

int main(){

  return 0;
}