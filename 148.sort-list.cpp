/*
 * @lc app=leetcode id=148 lang=cpp
 *
 * [148] Sort List
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
    ListNode* sortList(ListNode* head) {
        return mergeSortList(head);
    }
private:
    ListNode* mergeSortList(ListNode* root)
    {
        if (root == nullptr || root->next == nullptr) return root;

        ListNode* fast(root);
        ListNode* slow(root);
        ListNode* pre(root);

        while (fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            pre = slow;
            slow = slow->next;
        }

        pre->next = nullptr;
        ListNode* left = mergeSortList(root);
        ListNode* right = mergeSortList(slow);

        return mergeSortedList(left, right);
    }
    ListNode* mergeSortedList(ListNode* l, ListNode* r)
    {
        if (l == nullptr) return r;
        if (r == nullptr) return l;

        ListNode* dummy = new ListNode(0);
        ListNode* tmp(dummy);
        while (l != nullptr && r != nullptr)
        {
            if (l->val < r->val)
            {
                tmp->next = new ListNode(l->val);
                l = l->next;
            }
            else
            {
                tmp->next = new ListNode(r->val);
                r = r->next;
            }
            tmp = tmp->next;
        }
        while (l != nullptr)
        {
            tmp->next = new ListNode(l->val);
            l = l->next;
            tmp = tmp->next;
        }
        while (r != nullptr)
        {
            tmp->next = new ListNode(r->val);
            r = r->next;
            tmp = tmp->next;
        }

        tmp = dummy->next;
        delete dummy;
        return tmp;
    }
    /*
    ListNode* quickSortList(ListNode* head, ListNode* bound)
    {
        cout << "in" << endl;
        if (head == nullptr || head == bound || head->next == nullptr || head->next == bound) return head;
        
        ListNode* pivot(head);
        ListNode* left(nullptr);
        ListNode* leftend(nullptr);
        ListNode* right(nullptr);
        ListNode* rightend(nullptr);
        ListNode* tmp(head);
        cout << 'a' << tmp->val << endl;
        while(tmp != nullptr) {cout << 'x' << tmp->val;tmp= tmp->next;}
        cout << endl;
        tmp = head;

        while (tmp->next != bound)
        {
            if (tmp->next->val < pivot->val && left == nullptr)
            {
                left = tmp->next;
            }
            if (tmp->next->val >= pivot->val && right == nullptr)
            {
                right = tmp->next;
                tmp->next = right->next;
                if (tmp->next == bound) break;
                cout << right->val << tmp->val << endl;
            }
            cout << tmp->val << endl;
            tmp = tmp->next;
        }
        cout << 'b' << tmp->val << endl;
        if (left == nullptr)
        {
            quickSortList(head->next, nullptr);
            return head;
        }
        if (right == nullptr)
        {
            head->next = nullptr;
            tmp->next = head;
            quickSortList(left, head);
            return left;
        }
        right->next = nullptr;
        tmp->next = right;
        leftend = left;
        rightend = right;
        tmp = head->next;
        while (tmp != bound)
        {
            if (tmp->val < pivot->val) leftend = tmp; 
            else
            {
                leftend->next = tmp->next;
                rightend = tmp;
                right->next = rightend;
            }
            cout << tmp->val << endl;
            tmp = tmp->next;
        }
        leftend->next = pivot;
        rightend->next = nullptr;
        pivot->next = right;

        quickSortList(left, pivot);
        quickSortList(right, nullptr);

        return left;
    }
    */
};

