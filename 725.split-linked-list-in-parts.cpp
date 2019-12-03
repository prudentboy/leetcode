/*
 * @lc app=leetcode id=725 lang=cpp
 *
 * [725] Split Linked List in Parts
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
    vector<ListNode*> splitListToParts(ListNode* root, int k)
    {
        int l(lenOfList(root));
        int n(l / k), r(l % k);
        //cout << n << ' ' << r << endl;
        vector<ListNode*> ans;
        ListNode* head = new ListNode(-1);
        ListNode* t(nullptr);
        int tmp(n);
        while (k-- > 0)
        {
            tmp = n;
            if (r-- > 0) ++tmp;
            //cout << tmp << endl;
            if (root == nullptr || tmp == 0) ans.push_back(nullptr);
            else
            {
                head->next = nullptr;
                ListNode* t = head;
                while (root != nullptr && tmp-- > 0)
                {
                    //cout << k << ' ' << root->val << endl;
                    t->next = new ListNode(root->val);
                    t = t->next;
                    root = root->next;
                }
                ans.push_back(head->next);
            }
        }
        delete head;
        return ans;
    }
private:
    int lenOfList(ListNode* root)
    {
        if (root == nullptr) return 0;
        return 1 + lenOfList(root->next);
    }
};
// @lc code=end

