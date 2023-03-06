/*
 * @lc app=leetcode id=472 lang=cpp
 *
 * [472] Concatenated Words
 */

#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

// @lc code=start

struct Node {
    char c;
    bool end;
    map<char, Node*> child;
    Node(char _c, bool _end = false) : c(_c), end(_end) {};
};

class Solution {
public:
    void add(Node* root, string &str){
        int idx = 0;
        while(idx < str.size()){
            // find child
            auto it = root->child.find(str[idx]);
            if(it != root->child.end()) root = it->second;
            else {
                // add child
                Node* tmp = new Node(str[idx]);
                root->child[str[idx]] = tmp;
                root = tmp; 
            }
            idx++;
        }
        root->end = true;
    }

    bool concat(Node* root, Node* now, string &str, int idx){
        if(idx == str.size() && now->end) return true;
        if(now->end && concat(root, root, str, idx)) return true;
        
        auto it = now->child.find(str[idx]);
        if(it != now->child.end()) return concat(root, it->second, str, idx+1);
        
        return false;
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string &a, const string &b){
            return a.size() < b.size() || (a.size() == b.size() && a < b);
        });

        vector<string> ans;

        Node* root = new Node(' ');
        for(string &str : words){
            if(concat(root, root, str, 0)) ans.emplace_back(str);
            add(root, str);
        }

        return ans;
    }
};
// @lc code=end

