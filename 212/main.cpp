/*
 * @lc app=leetcode id=212 lang=cpp
 *
 * [212] Word Search II
 */

#include <vector>
#include <string>
#include <map>

using namespace std;

struct Node{
    map<char, Node*> children;
    char c;
    int idx;
    Node(char _c): c(_c), idx(-1) {}
};

// @lc code=start
class Solution {
public:
    void addWord(Node *root, string &s, int s_idx, int idx){
        if(s.size() == s_idx){
            root->idx = idx; 
            return;
        }
        char c = s[s_idx];
        if(root->children.count(c) == 0){
            // add
            Node* new_node = new Node(c);
            root->children[c] = new_node;
        }
        addWord(root->children[c], s, s_idx+1, idx);
    }

    void DFS(vector<vector<char>>& board, int i, int j, Node *root, vector<int> &found){
        if(root->idx != -1){
            found[root->idx] = 1;
        }
        if(root->children.size() == 0) return;
        if(i < 0 || i >= board.size()) return;
        if(j < 0 || j >= board.front().size()) return;
        if(root->children.count(board[i][j]) == 0) return;

        char tmp = board[i][j];
        board[i][j] = '.';

        Node* next = root->children[tmp];

        DFS(board, i+1, j, next, found);
        DFS(board, i, j-1, next, found);
        DFS(board, i-1, j, next, found);
        DFS(board, i, j+1, next, found);

        board[i][j] = tmp;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        // create Trie
        Node root(' ');
        int idx = 0;
        for(string s : words){
            addWord(&root, s, 0, idx++);
        }

        // DFS
        vector<int> found(words.size(), 0);
        for(int i = 0; i < board.size(); ++i){
            for(int j = 0; j < board.front().size(); ++j){
                DFS(board, i, j, &root, found);
            }
        }

        vector<string> result;
        for(int i = 0; i < words.size(); ++i){
            if(found[i]) result.emplace_back(words[i]);
        }

        return result;
    }
};
// @lc code=end

