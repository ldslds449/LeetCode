/*
 * @lc app=leetcode id=2130 lang=cpp
 *
 * [2130] Maximum Twin Sum of a Linked List
 */

// @lc code=start

#include <stack>

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
        ListNode *slow = &root, *fast = &root;
        std::stack<int> st;

        while(fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
            st.push(slow->val);
        }
        slow = slow->next;

        int max_val = 0;
        while(slow != nullptr){
            max_val = std::max(max_val, st.top()+slow->val);
            st.pop();
            slow = slow->next;
        }

        return max_val;
    }
};
// @lc code=end

