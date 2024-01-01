/*
 * @lc app=leetcode id=958 lang=cpp
 *
 * [958] Check Completeness of a Binary Tree
 */

// @lc code=start

#include <cmath>

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
    bool dfs(TreeNode* root, bool &less, int &height){
        if(!root){
            less = false;
            height = 0;
            return true;
        }else{
            bool left_less, right_less;
            int left_h, right_h;
            bool left = dfs(root->left, left_less, left_h);
            if(!left) return false;
            bool right = dfs(root->right, right_less, right_h);
            if(!right) return false;
            if(left_h < right_h) return false;
            if(left_h - right_h > 1) return false;
            if(left_h - right_h == 1 && right_less) return false;
            if(left_h - right_h == 0 && left_less) return false;
            height = max(left_h, right_h) + 1;
            less = left_h != right_h ? true : (left_less || right_less);
            return true;
        }
    }

    bool isCompleteTree(TreeNode* root) {
        if(!root) return true;
        bool a; int b;
        return dfs(root, a, b);
    }
};
// @lc code=end

