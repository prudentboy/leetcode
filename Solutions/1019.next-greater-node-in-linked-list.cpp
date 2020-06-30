/*
 * @lc app=leetcode id=1019 lang=cpp
 *
 * [1019] Next Greater Node In Linked List
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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> arr;
        while (head != nullptr) {
            arr.push_back(head->val);
            head = head->next;
        }

        stack<int> st;
        vector<int> ans(arr.size());
        for (int i(arr.size() - 1); i >= 0; --i) {
            while (!st.empty() && arr[i] >= st.top()) {
                st.pop();
            }
            ans[i] = st.empty() ? 0 : st.top();
            st.push(arr[i]);
        }
        
        return ans;
    }
};
// @lc code=end

