/*
 * @lc app=leetcode id=817 lang=cpp
 *
 * [817] Linked List Components
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
    int numComponents(ListNode* head, vector<int>& G) {
        int ans(0);
        unordered_map<int, int> m;
        for (int n : G) ++m[n];
        bool flag(false);
        while (true) {
            if (head == nullptr) {
                if (flag) ++ans;
                break;
            }
            if (m[head->val] == 0) {
                if (flag) ++ans;
                flag = false;
            } else {
                --m[head->val];
                flag = true;
            }
            head = head->next;
        }
        return ans;
    }
};
// @lc code=end

