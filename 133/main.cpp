/*
 * @lc app=leetcode id=133 lang=cpp
 *
 * [133] Clone Graph
 */

// @lc code=start

#include <vector>
#include <unordered_map>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    unordered_map<Node*, Node*> seen;

    Node* cloneGraph(Node* node) {
        if(node == nullptr) return nullptr;
        Node* dup = new Node(node->val);
        seen[node] = dup;
        for(Node* c : node->neighbors){
            if(seen.count(c)){
                dup->neighbors.push_back(seen[c]);
            }else{
                dup->neighbors.push_back(cloneGraph(c));
            }
            
        }
        return dup;
    }
};
// @lc code=end

