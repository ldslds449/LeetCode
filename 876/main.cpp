/*
 * @lc app=leetcode id=876 lang=cpp
 *
 * [876] Middle of the Linked List
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
    ListNode* middleNode(ListNode* head) {
        ListNode* fast = head, *slow = head;
        while(fast->next != nullptr){
            slow = slow->next;
            fast = fast->next;
            if(fast->next != nullptr) fast = fast->next;
        }
        return slow;
    }
};
// @lc code=end

