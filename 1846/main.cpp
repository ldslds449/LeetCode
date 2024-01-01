class Solution {
public:
  int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    int check = 1;
    for(int i = 0; i < arr.size(); ++i){
      if(arr[i] >= check) check++;
    }
    return check - 1;
  }
};
