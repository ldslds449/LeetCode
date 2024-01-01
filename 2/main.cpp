/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode head(0, l1), *pre_ptr = &head;
        while(l1 != nullptr && l2 != nullptr){
            l1->val += l2->val + carry;
            if(l1->val >= 10){
                carry = 1;
                l1->val -= 10;
            }else{
                carry = 0;
            }
            l1 = l1->next;
            l2 = l2->next;
            pre_ptr = pre_ptr->next;
        }

        if(l2 != nullptr){
            pre_ptr->next = l2;
            l1 = l2;
        }

        while(carry){
            if(l1 == nullptr){
                pre_ptr->next = new ListNode(carry, nullptr);
                break;
            }
            l1->val += carry;
            if(l1->val >= 10){
                carry = 1;
                l1->val -= 10;
            }else{
                carry = 0;
            }
            l1 = l1->next;
            pre_ptr = pre_ptr->next;
        }

        return head.next;
    }
};
// @lc code=end

