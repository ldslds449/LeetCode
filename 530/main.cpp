struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode() : val(0), left(nullptr), right(nullptr) {}
   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include <algorithm>

using namespace std;

class Solution {
public:
	int pre = -1;

	int getMinimumDifference(TreeNode* root) {
		if(!root) return 999999; 
		int left = getMinimumDifference(root->left);
		int ans = (pre == -1 ? left : min(left, root->val - pre));
		pre = root->val;
		int right = getMinimumDifference(root->right);
		return min(ans, right);
  }
}
