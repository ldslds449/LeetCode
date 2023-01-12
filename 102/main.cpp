/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
 */

// @lc code=start

#include <vector>

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr) return {};

        auto left = levelOrder(root->left);
        auto right = levelOrder(root->right);

        vector<vector<int>> cur;
        cur.push_back({root->val});

        int min_size = min(left.size(), right.size());
        for(int i = 0; i < min_size; ++i){
            vector<int> tmp;
            tmp.insert(tmp.end(), left[i].begin(), left[i].end());
            tmp.insert(tmp.end(), right[i].begin(), right[i].end());
            cur.push_back(tmp);
        }
        if(left.size() > min_size) cur.insert(cur.end(), left.begin()+min_size, left.end());
        if(right.size() > min_size) cur.insert(cur.end(), right.begin()+min_size, right.end());

        return cur;
    }
};
// @lc code=end

