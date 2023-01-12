/*
 * @lc app=leetcode id=652 lang=cpp
 *
 * [652] Find Duplicate Subtrees
 */

#include <vector>
#include <map>
#include <string>

using namespace std;

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
    map<string, int> m;
    vector<TreeNode*> answer;

    string dfs(TreeNode* root){
        if(root == nullptr) return "";

        string tmp = to_string(root->val) + " " + dfs(root->left) + " " + dfs(root->right);
        if(m.count(tmp) && m[tmp] == 1){
            answer.push_back(root);
        }
        m[tmp]++;

        return tmp;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        dfs(root);
        return answer;
    }
};
// @lc code=end

