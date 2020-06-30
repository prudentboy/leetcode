/*
 * @lc app=leetcode id=133 lang=cpp
 *
 * [133] Clone Graph
 */
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return nullptr;

        Node* ans = new Node();
        ans->val = node->val;
        
        unordered_set<Node*> visited;
        unordered_map<Node*, Node*> table;

        queue<Node*> q;
        queue<Node*> qNew;
        q.push(node);
        qNew.push(ans);

        Node* tmp(nullptr);
        Node* tmpNew(nullptr);
        while (!q.empty())
        {
            tmp = q.front();
            tmpNew = qNew.front();
            q.pop();
            qNew.pop();
            if (visited.count(tmp) > 0) continue;

            if (!tmp->neighbors.empty())
            {
                for (const auto nptr : tmp->neighbors)
                {
                    if (table.find(nptr) != table.end()) tmpNew->neighbors.push_back(table[nptr]);
                    else
                    {
                        Node* t = new Node();
                        t->val = nptr->val;
                        tmpNew->neighbors.push_back(t);
                        table[nptr] = t;
                        q.push(nptr);
                        qNew.push(t);
                    }
                }

            }
            visited.insert(tmp);
            table[tmp] = tmpNew;
        }
        return ans;
    }
};

