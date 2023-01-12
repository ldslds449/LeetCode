/*
 * @lc app=leetcode id=1339 lang=cpp
 *
 * [1339] Maximum Product of Splitted Binary Tree
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
    int sum(TreeNode* now){
        if(now == nullptr) return 0;
        now->val += sum(now->left) + sum(now->right);
        return now->val;
    }

    int total;
    long long max_product = 0;
    
    void dfs(TreeNode* now){
        if(now == nullptr) return ;
        if(now->left != nullptr){
            long long tmp = (long long)now->left->val * (total - now->left->val);
            max_product = max(max_product, tmp);
        }
        if(now->right != nullptr){
            long long tmp = (long long)now->right->val * (total - now->right->val);
            max_product = max(max_product, tmp);
        }
        dfs(now->left);
        dfs(now->right);
    }
    
    int maxProduct(TreeNode* root) {
        total = sum(root);
        dfs(root);
        return max_product % (long long)(1e9+7);
    }
};
// @lc code=end

