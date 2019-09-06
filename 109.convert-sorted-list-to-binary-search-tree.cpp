/*
 * @lc app=leetcode id=109 lang=cpp
 *
 * [109] Convert Sorted List to Binary Search Tree
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head)
    {
        vector<int> arr;
        while (head != nullptr)
        {
            arr.push_back(head->val);
            head = head->next;
        }
        return sortedArrayToBST(arr, 0, arr.size() - 1);
    }
private:
    TreeNode* sortedArrayToBST(vector<int> arr, size_t begin, size_t end)
    {
        if (begin > end or begin < 0 or end >= arr.size())  return nullptr;
        size_t mid = begin + ((end - begin) >> 1);
        TreeNode* root = new TreeNode(arr[mid]);
        root->left = sortedArrayToBST(arr, begin, mid - 1);
        root->right = sortedArrayToBST(arr, mid + 1, end);
        return root;
    }
};

