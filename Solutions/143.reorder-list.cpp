/*
 * @lc app=leetcode id=143 lang=cpp
 *
 * [143] Reorder List
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr || head->next->next == nullptr) return;

        ListNode* second(head->next);
        ListNode* pre(head);
        ListNode* tail(second);

        while (tail->next != nullptr)
        {
            pre = pre->next;
            tail = tail->next;
        }

        tail->next = second;
        pre->next = nullptr;
        head->next = tail;
        
        reorderList(second);
    }
};

