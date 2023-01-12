#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    long long minimumTotalCost(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> freq;
        int total_dup = 0;
        long long ans = 0;
        int max_num, max_val = -1;
        for(int i = 0; i < nums1.size(); ++i){
            if(nums1[i] == nums2[i]){
              freq[nums1[i]]++;
              total_dup++;
              ans += i;
              if(freq[nums1[i]] > max_val){
                max_val = freq[nums1[i]];
                max_num = nums1[i];
              }
            }
        }
        // not enough
        int idx = 0, add = 0;
        while(max_val*2 > (total_dup + add) && idx < nums1.size()){
            if(nums1[idx] == nums2[idx] || nums1[idx] == max_num || nums2[idx] == max_num){
              idx++; continue;
            }
            ans += idx;
            add++;
            idx++;
        }

        return (max_val*2 > (total_dup + add)) ? -1 : ans;
    }
};