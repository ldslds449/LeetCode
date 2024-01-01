class NumArray {
public:
  vector<int> presum;

  NumArray(vector<int>& nums) : presum(nums.size()+1, 0) {
    for(int i = 0; i < nums.size(); ++i){
      presum[i+1] = presum[i] + nums[i];
    }
  }

  int sumRange(int left, int right) {
    return presum[right+1] - presum[left];
  }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
