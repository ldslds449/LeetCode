/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 */

#include <vector>
#include <string>

using namespace std;

// @lc code=start
class Trie {
public:
    struct Node{
        vector<Node*> children;
        char c;
        bool end;
        Node(char _c): c(_c), end(false) {}
    };
    
    Node* root;

    Trie() {
        root = new Node(' ');
    }
    
    void insert(string word) {
        Node* now = root;
        for(char w : word){
            bool found = false;
            for(Node* n : now->children){
                if(n->c == w){
                    now = n; found = true; break;
                }
            }
            if(found) continue;
            Node* new_n = new Node(w);
            now->children.push_back(new_n);
            now = new_n;
        }
        now->end = true;
    }

    Node* findNode(const string &word){
        Node* now = root;
        for(char w : word){
            bool found = false;
            for(Node* n : now->children){
                if(n->c == w){
                    now = n; found = true; break;
                }
            }
            if(found) continue;
            return nullptr;
        }
        return now;
    }
    
    bool search(string word) {
        Node* n = findNode(word);
        return n != nullptr && n->end;
    }
    
    bool startsWith(string prefix) {
        Node* n = findNode(prefix);
        return n != nullptr;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

