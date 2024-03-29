#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<int> getAverages(vector<int>& nums, int k) {
		if(nums.size() < 2*k+1) return vector<int>(nums.size(), -1);
		
    int N = nums.size();
		vector<int> ans(N, -1);
    nums.push_back(0);

		long long sum = 0;
		for(int i = 0; i < 2*k+1; ++i){
			sum += nums[i];
		}

		for(int i = k; i < N-k; ++i){
			ans[i] = sum / (2*k+1);
			sum += nums[i+k+1];
			sum -= nums[i-k];
		}
		
		return ans;
	}
};
