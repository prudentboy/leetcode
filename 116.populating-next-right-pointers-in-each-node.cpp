/*
 * @lc app=leetcode id=116 lang=cpp
 *
 * [116] Populating Next Right Pointers in Each Node
 */
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) return nullptr;
        
        std::vector<Node*> v_node;
        Node* tmp;
        v_node.push_back(root);
        int index(0);

        while (index < v_node.size())
        {
            tmp = v_node[index];
            if (tmp != nullptr)
            {
                v_node.push_back(tmp->left);
                v_node.push_back(tmp->right);
            }
            ++index;
        }

        for (size_t i = 0; i < v_node.size(); ++i)
        {
            if (v_node[i] == nullptr) continue;
            if (isRightIndex(i)) v_node[i]->next = nullptr;
            else v_node[i]->next = v_node[i + 1];
        }

        return root;
    }
private:
    bool isRightIndex(size_t n)
    {
        n += 2;
        return (n & (n - 1)) == 0;
    }
};

