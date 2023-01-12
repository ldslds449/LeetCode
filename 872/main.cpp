/*
 * @lc app=leetcode id=872 lang=cpp
 *
 * [872] Leaf-Similar Trees
 */

// @lc code=start

#include <stack>
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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> values;
        stack<TreeNode*> s;

        s.push(root1);
        while(!s.empty()){
            TreeNode *now = s.top(); s.pop();
            if(now->left == nullptr && now->right == nullptr){
                values.push_back(now->val);
            }else{
                if(now->right != nullptr) s.push(now->right);
                if(now->left != nullptr) s.push(now->left);
            }
        }

        int idx = 0;
        s.push(root2);
        while(!s.empty()){
            TreeNode *now = s.top(); s.pop();
            if(now->left == nullptr && now->right == nullptr){
                if(idx >= values.size() || values[idx++] != now->val) return false;
            }else{
                if(now->right != nullptr) s.push(now->right);
                if(now->left != nullptr) s.push(now->left);
            }
        }

        return idx == values.size();
    }
};
// @lc code=end

