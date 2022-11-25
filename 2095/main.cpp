/*
 * @lc app=leetcode id=2095 lang=cpp
 *
 * [2095] Delete the Middle Node of a Linked List
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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode root(-1, head);
        ListNode* middle = &root;
        ListNode* now = &root;
        while(now->next != nullptr && now->next->next != nullptr){
            now = now->next->next;
            middle = middle->next;
        }
        // delete
        ListNode* del = middle->next;
        middle->next = del->next;
        delete del;

        return root.next;
    }
};
// @lc code=end

