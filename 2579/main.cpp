class Solution {
public:
  long long coloredCells(int n) {
    if(n == 1) return 1;
    long long cnt = 1; int edge = 2;
    for(int i = 1; i < n; ++i){
      cnt += (edge - 1) * 4;
      edge++;
    }
    return cnt;
  }
};
