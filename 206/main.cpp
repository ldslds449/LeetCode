/*
 * @lc app=leetcode id=206 lang=cpp
 *
 * [206] Reverse Linked List
 */

// @lc code=start

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* new_head = nullptr;

    ListNode* helper(ListNode* head) {
        if(head->next == nullptr){
            new_head = head; return head;
        }
        helper(head->next)->next = head;
        return head;
    }

    ListNode* reverseList(ListNode* head) {
        if(head == nullptr) return nullptr;
        helper(head)->next = nullptr;
        return new_head;
    }
};
// @lc code=end

