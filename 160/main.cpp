/*
 * @lc app=leetcode id=160 lang=cpp
 *
 * [160] Intersection of Two Linked Lists
 */

// @lc code=start

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // reverse value
        ListNode* rootA = headA;
        while(rootA != nullptr){
            rootA->val = -rootA->val;
            rootA = rootA->next;
        }
        // find reverse value
        while(headB != nullptr){
            if(headB->val < 0) break;
            headB = headB->next;
        }
        ListNode* rootB = headB;
        // recovery
        while(headA != nullptr){
            headA->val = -headA->val;
            headA = headA->next;
        }

        return rootB;
    }
};
// @lc code=end

