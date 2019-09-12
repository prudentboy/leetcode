/*
 * @lc app=leetcode id=142 lang=cpp
 *
 * [142] Linked List Cycle II
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
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return nullptr;

        ListNode* slow(head);
        ListNode* fast(head);

        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) break;
        }

        if (fast != slow) return nullptr;

        slow = head;
        while (slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
    }
};

