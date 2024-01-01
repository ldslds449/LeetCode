class Solution {
public:
  int sumFourDivisors(vector<int>& nums) {
    int total = 0;
    for(int i = 0; i < nums.size(); ++i){
      int &num = nums[i];
      if((num == 1) || (num == (int)sqrt(num) * (int)sqrt(num))) continue;
      int cnt = 0;
      int sum = num + 1;
      for(int j = 2; j <= (int)sqrt(num); ++j){
        if(num % j == 0){
          cnt += 2;
          sum += j + (num/j);
        }
      }
      if(cnt == 2) total += sum;
    }
    return total;
  }
};


