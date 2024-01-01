/*
 * @lc app=leetcode id=870 lang=cpp
 *
 * [870] Advantage Shuffle
 */

// @lc code=start
class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        multiset<int> s(nums1.begin(), nums1.end());
        for(int i = 0; i < nums2.size(); ++i){
          auto it = s.upper_bound(nums2[i]);
          if(it == s.end()){
            it = s.begin();
          }
          nums1[i] = *it;
          s.erase(it);
        }
        return nums1;
    }
};
// @lc code=end

