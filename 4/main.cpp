#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

class Solution {
public:

  int found(vector<int> &nums1, vector<int> &nums2, int target_idx){
    int start = max(0, target_idx-(int)nums2.size()), end = min((int)nums1.size(), target_idx+1);
    while(start < end){
      int mid = (end - start) / 2 + start;
      int idx = target_idx - mid - 1;
      if(idx < 0 || nums2[idx] < nums1[mid]){
        if(idx+1 >= nums2.size() || nums2[idx+1] >= nums1[mid]){
          // found
          return nums1[mid];
        }else{
          end = mid;
        }
      }else if(nums2[idx] > nums1[mid]){
        start = mid+1;
      }else{ // equal
        // found
        return nums1[mid];
      }
    }
    return -1;
  }

  int job(vector<int> &nums1, vector<int> &nums2, int target_idx){
    int r = found(nums1, nums2, target_idx);
    if(r < 0){
      return found(nums2, nums1, target_idx);
    }
    return r;
  }

  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int target_idx1 = (nums1.size() + nums2.size()) / 2;
    int target_idx2 = (nums1.size() + nums2.size()-1) / 2;
    int r1 = job(nums1, nums2, target_idx1);
    int r2 = r1;
    if(target_idx1 != target_idx2){
      r2 = job(nums1, nums2, target_idx2);
    }
    return (double)(r1 + r2) / 2;
  }
};

int main(){
  Solution s;
  vector<int> a{1,3}, b{2};
  cerr << s.findMedianSortedArrays(a, b);
  return 0;
}