/*
 * @lc app=leetcode id=124 lang=cpp
 *
 * [124] Binary Tree Maximum Path Sum
 */

// @lc code=start

#include <algorithm>

using namespace std;

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
    int maxSum;

    int dfs(TreeNode* now){
        if(now == nullptr) return 0;
        maxSum = max(maxSum, now->val);
        int left = dfs(now->left);
        int right = dfs(now->right);
        int tmp = max(now->val + left, now->val + right);
        tmp = max(tmp, now->val);
        maxSum = max(maxSum, tmp);
        maxSum = max(maxSum, now->val + left + right);
        return tmp;
    }

    int maxPathSum(TreeNode* root) {
        maxSum = root->val;
        dfs(root);
        return maxSum;
    }
};
// @lc code=end

