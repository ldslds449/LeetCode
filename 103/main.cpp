/*
 * @lc app=leetcode id=103 lang=cpp
 *
 * [103] Binary Tree Zigzag Level Order Traversal
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
    vector<vector<int>> ans;

    void dfs(TreeNode* node, int level){
        if(!node) return;
        if(ans.size() <= level) ans.push_back({});
        ans[level].push_back(node->val);
        dfs(node->left, level+1);
        dfs(node->right, level+1);
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        dfs(root, 0);
        for(int i = 1; i < ans.size(); i+=2){
            reverse(ans[i].begin(), ans[i].end());
        }
        return ans;
    }
};
// @lc code=end

