/*
 * @lc app=leetcode id=141 lang=cpp
 *
 * [141] Linked List Cycle
 */

#include <unordered_set>

using namespace std;

// @lc code=start

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> s;
        while(head != nullptr){
            if(s.count(head)) return true;
            s.insert(head);
            head = head->next;
        }
        return false;
    }
};
// @lc code=end

