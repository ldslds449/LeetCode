/*
 * @lc app=leetcode id=783 lang=cpp
 *
 * [783] Minimum Distance Between BST Nodes
 */

// @lc code=start

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include <algorithm>
#include <utility>

using namespace std;

class Solution {
public:
    int diff = 99999999;

    pair<int,int> dfs(TreeNode* node){
        int max_val = node->val;
        int min_val = node->val;
        if(node->left){
            auto val_left = dfs(node->left);
            diff = min(diff, abs(val_left.first - node->val));
            min_val = min(min_val, val_left.second);
        }
        
        if(node->right){
            auto val_right = dfs(node->right);
            diff = min(diff, abs(val_right.second - node->val));
            max_val = max(max_val, val_right.first);
        }
        return {max_val, min_val};
    }

    int minDiffInBST(TreeNode* root) {
        dfs(root);
        return diff;
    }
};
// @lc code=end

