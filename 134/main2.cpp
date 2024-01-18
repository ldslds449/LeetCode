class Solution {
public:
  int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int total = 0;
    int current = 0;
    int start_pos = 0;
    for(int i = 0; i < gas.size(); ++i){
      int diff = gas[i] - cost[i];
      total += diff;
      current += diff;
      if(current < 0){
        start_pos = i + 1;
        current = 0;
      }
    }
    return total >= 0 ? start_pos : -1;
  }
};
