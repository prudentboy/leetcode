/*
 * @lc app=leetcode id=1171 lang=cpp
 *
 * [1171] Remove Zero Sum Consecutive Nodes from Linked List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode dummy(0, head);
        ListNode* cur(dummy.next);

        unordered_map<int, ListNode*> ump;
        ump[0] = &dummy;
        int curSum(0);
        while (cur != nullptr) {
            curSum += cur->val;
            if (ump.count(curSum) > 0) {
                ListNode* tmp(ump[curSum]->next);
                int v(curSum);
                ump[curSum]->next = cur->next;
                while (tmp != cur) {
                    v += tmp->val;
                    ump.erase(v);
                    tmp = tmp->next;
                }
            } else {
                ump[curSum] = cur;
            }
            cur = cur->next;
        }
        return dummy.next;
    }
};
// @lc code=end

