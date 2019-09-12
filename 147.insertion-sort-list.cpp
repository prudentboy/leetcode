/*
 * @lc app=leetcode id=147 lang=cpp
 *
 * [147] Insertion Sort List
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
    ListNode* insertionSortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;

        ListNode* pre(head);
        ListNode* now(head->next);
        ListNode* next(nullptr);
        ListNode* tmp(nullptr);

        while (now != nullptr)
        {
            next = now->next;
            pre->next = next;
            if (now->val < head->val)
            {
                now->next = head;
                head = now;
            }
            else
            {
                tmp = head;
                while (tmp != pre && tmp->next->val < now->val) tmp = tmp->next;
                now->next = tmp->next;
                tmp->next = now;
                if (tmp == pre) pre = now;
            }
            now = next;
        }

        return head;
    }
};

