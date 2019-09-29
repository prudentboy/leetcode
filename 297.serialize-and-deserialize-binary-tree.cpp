/*
 * @lc app=leetcode id=297 lang=cpp
 *
 * [297] Serialize and Deserialize Binary Tree
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
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string enStr;
        if (root == nullptr) return enStr;

        queue<TreeNode*> q;
        q.push(root);
        TreeNode* tmp;

        while (!q.empty())
        {
            tmp = q.front();
            q.pop();
            if (tmp == nullptr)
            {
                enStr.append("# ");
                continue;
            }
            else
            {
                enStr.append(to_string(tmp->val)).append(" ");
                q.push(tmp->left);
                q.push(tmp->right);
            }
        }

        //cout << enStr << endl;
        return enStr;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;

        istringstream iss(data);
        string now;
        queue<TreeNode*> q;
        iss >> now;
        int val(stoi(now));
        //cout << now << endl;
        TreeNode* root(new TreeNode(val));
        TreeNode* tmp;
        q.push(root);
        while (!q.empty())
        {
            tmp = q.front();
            q.pop();
            if (iss >> now && !now.empty() && now != "#")
            {
                val = stoi(now);
                tmp->left = new TreeNode(val);
                q.push(tmp->left);
            }
            if (iss >> now && !now.empty() && now != "#")
            {
                val = stoi(now);
                tmp->right = new TreeNode(val);
                q.push(tmp->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

