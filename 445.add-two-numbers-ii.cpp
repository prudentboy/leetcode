/*
 * @lc app=leetcode id=445 lang=cpp
 *
 * [445] Add Two Numbers II
 */

// @lc code=start
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        stack<int> s1(getNumStack(l1)), s2(getNumStack(l2));

        ListNode* ans(new ListNode(1));
        ListNode* tmp(nullptr);

        int num(0);
        while (!s1.empty() || !s2.empty())
        {
            if (!s1.empty())
            {
                num += s1.top();
                s1.pop();
            }
            if (!s2.empty())
            {
                num += s2.top();
                s2.pop();
            }
            ListNode* n(new ListNode(num % 10));
            n->next = ans->next;
            ans->next = n;
            num /= 10;
        }
        return num == 0 ? ans->next : ans;
    }
private:
    stack<int> getNumStack(ListNode* l)
    {
        stack<int> s;
        ListNode* tmp(l);
        while (tmp != nullptr)
        {
            s.push(tmp->val);
            tmp = tmp->next;
        }
        return s;   
    }
};
// @lc code=end

