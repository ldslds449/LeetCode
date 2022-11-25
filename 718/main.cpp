#include <iostream>
#include <array>
#include <vector>

using namespace std;

class Solution {
public:
  array<array<int, 1001>, 1001> table;

  int findLength(vector<int>& nums1, vector<int>& nums2) {
    // initial
    for(int i = 0; i <= nums1.size(); ++i){
      table[i][0] = 0;
    }
    for(int i = 0; i <= nums2.size(); ++i){
      table[0][i] = 0;
    } 
    
    // fill & find
    int max_value = 0;
    for(int i = 1; i <= nums1.size(); ++i){
      for(int k = 1; k <= nums2.size(); ++k){
        if(nums1[i-1] != nums2[k-1]){
          table[i][k] = 0;
        }else{
          table[i][k] = table[i-1][k-1] + 1;
          max_value = max(max_value, table[i][k]);
        }
      }
    }
    
    return max_value;
  }
};

int main(){

  vector<int> a{1,2,3,2,1};
  vector<int> b{3,2,1,4,7};

  Solution s;
  cerr << s.findLength(a,b) << "\n";

  return 0;
}