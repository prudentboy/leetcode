/*
 * @lc app=leetcode id=382 lang=cpp
 *
 * [382] Linked List Random Node
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
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) : l_(head)
    {
        srand(time(nullptr));
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int ans(l_->val), i(2);
        ListNode* tmp(l_->next);
        while (tmp != nullptr)
        {
            if (rand() % i++ == 0) ans = tmp->val;
            tmp = tmp->next;
        }
        return ans;
    }
private:
    ListNode* l_;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
// @lc code=end

