/*
 * @lc app=leetcode id=449 lang=cpp
 *
 * [449] Serialize and Deserialize BST
 */

// @lc code=start
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
        string ans;
        queue<TreeNode*> q;
        TreeNode* tmp(nullptr);
        q.push(root);
        while (!q.empty())
        {
            tmp = q.front();
            q.pop();
            if (tmp == nullptr) ans.append("# ");
            else
            {
                ans.append(to_string(tmp->val));
                ans += ' ';
                q.push(tmp->left);
                q.push(tmp->right);
            }
        }
        //cout << ans << endl;
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        size_t found = data.find_first_of(' ');
        if (found == string::npos) return nullptr;
        
        string now(data.substr(0, found));
        //cout << now << endl;
        if (now == "#") return nullptr;
        TreeNode* root = new TreeNode(stoi(now));
        queue<TreeNode*> q;
        TreeNode* tmp(nullptr);
        q.push(root);
        size_t start(found + 1);
        while (!q.empty())
        {
            tmp = q.front();
            q.pop();
            start = found + 1;
            found = data.find_first_of(' ', start);
            now = data.substr(start, found - start);
            //cout << start << ' ' << found << ' ' << now << '-';
            if (now != "#")
            {
                tmp->left = new TreeNode(stoi(now));
                q.push(tmp->left);
            }
            start = found + 1;
            found = data.find_first_of(' ', start);
            now = data.substr(start, found - start);
            //cout << start << ' ' << found << ' ' << now << endl;
            if (now != "#")
            {
                tmp->right = new TreeNode(stoi(now));
                q.push(tmp->right);
            }
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
// @lc code=end

