#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> s;
        for(int i = 0; i < min((int)nums.size(), k); ++i){
          if(s.count(nums[i])) return true;
          else s.insert(nums[i]);
        }
        for(int i = min((int)nums.size(), k); i < nums.size(); ++i){
          if(s.count(nums[i])) return true;
          else{
            s.insert(nums[i]);
            s.erase(nums[i-k]);
          }
        }
        return false;
    }
};