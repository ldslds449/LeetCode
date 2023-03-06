/*
 * @lc app=leetcode id=460 lang=cpp
 *
 * [460] LFU Cache
 */

#include <unordered_map>

using namespace std;

// @lc code=start
class FreqNode;
class Node{
public:
    int key;
    Node *prev, *next;
    FreqNode* parent;
    Node(int _k, Node* _prev, Node* _next, FreqNode* _p): key(_k), prev(_prev), next(_next), parent(_p){}
};

class FreqNode{
public:
    int freq;
    Node *child_head, *child_tail;
    FreqNode *prev, *next;
    FreqNode(int _f, Node* _c_head, Node* _c_tail, FreqNode* _prev, FreqNode* _next): freq(_f), child_head(_c_head), child_tail(_c_tail), prev(_prev), next(_next){}
};

class LFUCache {
public:
    int max_size, size = 0;

    unordered_map<int,pair<Node*,int>> table; // store the node & the value
    FreqNode* root = nullptr; // store the frequency

    LFUCache(int capacity) {
        max_size = capacity;
    }
    
    int get(int key) {
        auto it = table.find(key);
        if(it != table.end()){
            Node* node = it->second.first;
            FreqNode* fnode = node->parent;
            int freq = fnode->freq + 1;

            if(node->prev != nullptr) node->prev->next = node->next;
            else fnode->child_head = node->next;
            if(node->next != nullptr) node->next->prev = node->prev;
            else fnode->child_tail = node->prev;

            if(fnode->next == nullptr || fnode->next->freq != freq){
                FreqNode* new_f = new FreqNode(freq, node, node, fnode, fnode->next);
                if(fnode->next != nullptr) fnode->next->prev = new_f;
                fnode->next = new_f;

                node->parent = new_f;
                node->next = node->prev = nullptr;
            }else{
                node->parent = fnode->next;
                node->next = nullptr;
                node->prev = node->parent->child_tail;
                node->parent->child_tail->next = node;
                node->parent->child_tail = node;
            }

            if(fnode->child_head == nullptr){
                if(fnode->prev != nullptr){
                    fnode->prev->next = fnode->next;
                    fnode->next->prev = fnode->prev;
                }else{
                    fnode->next->prev = nullptr;
                    root = fnode->next;
                }
                delete fnode;
            }

            return it->second.second;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(get(key) != -1){
            table[key] = {table[key].first, value};
            return;
        }

        if(size == max_size){ // full
            if(size == 0) return;
            // discard the LFU element
            table.erase(root->child_head->key);
            // discard the nodes
            Node* node = root->child_head->next;
            delete root->child_head;
            if(node != nullptr){
                node->prev = nullptr;
                root->child_head = node;
            }else{
                FreqNode* fnode = root->next;
                delete root;
                if(fnode != nullptr) fnode->prev = nullptr;
                root = fnode;
            }
            size--;
        }
        // add new nodes
        if(root == nullptr || root->freq != 0){
            FreqNode* tmp = new FreqNode(0, nullptr, nullptr, nullptr, root);
            if(root != nullptr) root->prev = tmp;
            root = tmp;
        }
        Node* tmp = new Node(key, root->child_tail, nullptr, root);
        if(root->child_tail == nullptr){
            root->child_head = root->child_tail = tmp;
        }else{
            root->child_tail->next = tmp;
            root->child_tail = tmp;
        }
        // add new element
        table[key] = {tmp, value};

        size++;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

