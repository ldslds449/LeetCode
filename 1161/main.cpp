
// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
	vector<int> sum;

	void dfs(TreeNode* now, int level){
		if(!now) return;
		if(sum.size() <= level) sum.push_back(now->val);
		else sum[level] += now->val;
		
		dfs(now->left, level+1);
		dfs(now->right, level+1);
	}

	int maxLevelSum(TreeNode* root) {
  	dfs(root, 0);
		
		int max_idx, max_val = INT32_MIN;
			
		for(int i = 0; i < sum.size(); ++i){
			if(max_val < sum[i]){
				max_val = sum[i];
				max_idx = i+1;
			}
		}

		return max_idx;
	}
};
