#include <string>

using namespace std;

class Solution {
public:
	vector<string> summaryRanges(vector<int>& nums) {
		int start = nums.size() > 0 ? nums[0] : 0, end = start;
		vector<string> ans;
		for(int i = 1; i <= nums.size(); ++i){
			if(i < nums.size() && (long long)nums[i] - end == 1) end++;
			else{
				if(start != end){
					ans.push_back(to_string(start) + "->" + to_string(end));
				}else{
					ans.push_back(to_string(start));
				}
				if(i < nums.size()){
					start = end = nums[i];
				}
			}
		}
		return ans;
	}
};
