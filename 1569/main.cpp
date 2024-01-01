#include <vector>

using namespace std;

#define MOD (static_cast<long long>(1e9 + 7))

class Solution {
public:
	long long dfs(vector<int> &nodes, vector<vector<long long>> &ncr){
		if(nodes.size() == 0) return 1;
		int root = nodes[0];

		vector<int> left, right;
		for(int i = 1; i < nodes.size(); ++i){
			int &c = nodes[i];
			if(c > root) right.push_back(c);
			else left.push_back(c);
		}

		long long left_cnt = dfs(left, ncr) % MOD;
		long long right_cnt = dfs(right, ncr) % MOD;
		long long total_cnt = left_cnt * right_cnt % MOD;

		return (ncr[left.size() + right.size()][left.size()] * total_cnt) % MOD;

	}

  int numOfWays(vector<int>& nums) {
		int m = nums.size();

		vector<vector<long long>> ncr(m+1);
		for(int i = 0; i < m+1; ++i){
			ncr[i] = vector<long long>(i+1, 1);
			for(int k = 1; k < i; ++k){
				ncr[i][k] = (ncr[i-1][k] + ncr[i-1][k-1]) % MOD;
			}
		}

		return dfs(nums, ncr) % MOD - 1;
  }
};
