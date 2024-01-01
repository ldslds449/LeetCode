#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int largestAltitude(vector<int>& gain) {
		int max_val = 0;
		int now = 0;
		for(int i = 0; i < gain.size(); ++i){
			now += gain[i];
			max_val = max(max_val, now);
		}

		return max_val;
	}
};
