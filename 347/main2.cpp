#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:

    int quickSelect(vector<pair<int,int>>& arr, int start, int end, int k){
      int pivot = start, idx = start+1;
      for(int i = start+1; i < end; ++i){
        if(arr[i].second < arr[pivot].second){
          swap(arr[i], arr[idx++]);
        }
      }
      swap(arr[pivot], arr[idx-1]);
      int rank = idx - pivot;
      if(rank == k) return idx-1;
      else if(rank < k) return quickSelect(arr, idx, end, k - rank);
      else return quickSelect(arr, start, idx-1, k);
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        for(int n : nums) freq[n]++;

        vector<pair<int,int>> rank(freq.begin(), freq.end());
        
        int last = quickSelect(rank, 0, rank.size(), rank.size()-k+1);

        vector<int> r;
        for(int i = rank.size()-1; i >= last; --i){
            r.push_back(rank[i].first);
        }
        return r;
    }
};