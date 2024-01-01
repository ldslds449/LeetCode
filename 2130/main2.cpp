/*
 * @lc app=leetcode id=2130 lang=cpp
 *
 * [2130] Maximum Twin Sum of a Linked List
 */

// @lc code=start

#include <algorithm>

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
    int pairSum(ListNode* head) {
        ListNode root(0, head);
        ListNode *slow = &root, *fast = &root, *pre_slow = &root, *tmp = root.next;

        while(fast->next != nullptr){
            slow = tmp;
            fast = fast->next->next;
            // reverse
            tmp = slow->next;
            slow->next = pre_slow;
            pre_slow = slow;
        }
        fast = slow;
        slow = pre_slow;

        int max_val = 0;
        while(fast != nullptr){
            max_val = std::max(max_val, slow->val+fast->val);
            slow = slow->next;
            fast = fast->next;
        }

        return max_val;
    }
};
// @lc code=end

