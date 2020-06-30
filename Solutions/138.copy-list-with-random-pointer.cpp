/*
 * @lc app=leetcode id=138 lang=cpp
 *
 * [138] Copy List with Random Pointer
 */
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;

        Node* ans = new Node(head->val, nullptr, nullptr);
        unordered_map<Node*, Node*> table;
        table[head] = ans;

        Node* tmp(head);
        Node* tmpNew(ans);

        while (tmp->next != nullptr)
        {
            tmpNew->next = new Node(tmp->next->val, nullptr, nullptr);
            tmp = tmp->next;
            tmpNew = tmpNew->next;
            table[tmp] = tmpNew;
        }
        tmpNew = ans;
        tmp = head;
        while (tmpNew != nullptr && tmp != nullptr)
        {
            tmpNew->random = table[tmp->random];
            tmp = tmp->next;
            tmpNew = tmpNew->next;
        }

        return ans;
    }
};

