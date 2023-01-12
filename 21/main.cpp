/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* root = nullptr, *now = nullptr;
        while(list1 != nullptr && list2 != nullptr){
            ListNode** choose = (list1->val < list2->val ? &list1 : &list2);
            if(root == nullptr){
                root = *choose;
                now = *choose;
            }else{
                now->next = *choose;
                now = now->next;
            }
            *choose = (*choose)->next;
        }
        if(list1 != nullptr){
            if(root == nullptr) root = list1;
            else now->next = list1;
        }
        if(list2 != nullptr){
            if(root == nullptr) root = list2;
            else now->next = list2;
        }
        return root;
    }
};
// @lc code=end

