#include <vector>
#include <unordered_map>

using namespace std;

struct vec_hash{
	std::size_t operator()(vector<int> const &arr) const {
		int hash = 0;
		for(const int &v : arr) hash ^= v;
		return hash;
	}
};

class Solution {
public:
  int equalPairs(vector<vector<int>>& grid) {
		const int N = grid.size();
		unordered_map<vector<int>, int, vec_hash> m;

		for(int i = 0; i < N; ++i) m[grid[i]]++;
		
		int ans = 0;
		vector<int> tmp(N);
		for(int i = 0; i < N; ++i){
			for(int k = 0; k < N; ++k){
				tmp[k] = grid[k][i];
			}
			ans += m[tmp];
		}

		return ans;
  }
};
