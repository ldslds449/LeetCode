/*
 * @lc app=leetcode id=337 lang=cpp
 *
 * [337] House Robber III
 */

// @lc code=start

#include <algorithm>
#include <unordered_map>

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

    unordered_map<TreeNode*,int> cache_choosed, cache_unchoosed;

    int helper(TreeNode* root, bool choosed){
        if(root == nullptr) return 0;
        if(choosed){
            if(cache_choosed.count(root)) return cache_choosed[root];
            int val = helper(root->left, false) + helper(root->right, false);
            cache_choosed[root] = val;
            return val;
        }else{
            if(cache_unchoosed.count(root)) return cache_unchoosed[root];
            int val = max(
                // choose this node
                helper(root->left, true) + helper(root->right, true) + root->val,
                // do not choose this node
                helper(root->left, false) + helper(root->right, false)
            );
            cache_unchoosed[root] = val;
            return val;
        }
    }

    int rob(TreeNode* root) {
        return helper(root, false);
    }
};
// @lc code=end

