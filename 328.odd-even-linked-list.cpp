/*
 * @lc app=leetcode id=328 lang=cpp
 *
 * [328] Odd Even Linked List
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
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr || head->next->next == nullptr) return head;
        int len(1);
        ListNode* tmp(head);
        ListNode* tail(nullptr);
        while (tmp->next != nullptr)
        {
            ++len;
            tmp = tmp->next;
        }
        tail = tmp;
        //cout << len << ' ' << tail->val << endl;

        tmp = head;
        len >>= 1;
        while (len-- > 0)
        {
            //cout << len << ' ' << tmp->val << ' ' << tail->val << endl;
            tail->next = tmp->next;
            tmp->next = tmp->next->next;
            tail->next->next = nullptr;

            tmp = tmp->next;
            tail = tail->next;
        }

        return head;
    }
};

