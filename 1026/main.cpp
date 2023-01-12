/*
 * @lc app=leetcode id=1026 lang=cpp
 *
 * [1026] Maximum Difference Between Node and Ancestor
 */

// @lc code=start

#include <vector>
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
    int max_diff = 0;;

    void dfs(TreeNode* now, int max_val, int min_val){
        if(now == nullptr) return;

        max_val = max(max_val, now->val);
        min_val = min(min_val, now->val);
        max_diff = max(max_diff, 
            max_val - min_val
        );

        dfs(now->left, max_val, min_val);
        dfs(now->right, max_val, min_val);
    }

    int maxAncestorDiff(TreeNode* root) {
        dfs(root, -1, 9999999);
        return max_diff;
    }
};
// @lc code=end

