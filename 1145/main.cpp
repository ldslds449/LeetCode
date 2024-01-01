/*
 * @lc app=leetcode id=1145 lang=cpp
 *
 * [1145] Binary Tree Coloring Game
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

class Solution {
public:
    int left, right;

    int count(TreeNode* now, int x){
        if(now == nullptr) return 0;
        int l = count(now->left, x);
        int r = count(now->right, x);
        if(now->val == x){
            left = l;
            right = r;
        }
        return l + r + 1;
    }

    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        count(root, x);
        int parent = n - left - right  - 1;
        return (parent > left + right) ||
            (left > parent + right) ||
            (right > parent + left);
    }
};
// @lc code=end

