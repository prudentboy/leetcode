/*
 * @lc app=leetcode id=212 lang=cpp
 *
 * [212] Word Search II
 */
class Solution {
    struct PrefixTrieNode
    {
        unordered_map<char, PrefixTrieNode*> m_node;
        string str;
    };
    struct PrefixTrie
    {
        PrefixTrieNode* root;
        PrefixTrie() : root(new PrefixTrieNode()) {}
        void insert(const string& s)
        {
            PrefixTrieNode* tmp(root);
            for (int i(0); i < s.size(); ++i)
            {
                if (tmp->m_node.count(s[i]) == 0)
                {
                    tmp->m_node[s[i]] = new PrefixTrieNode();
                }
                tmp = tmp->m_node[s[i]];
            }
            tmp->str = s;
        }
    };
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        if (words.empty() || board.empty() || board[0].empty()) return {};

        PrefixTrie preTree;
        for (const auto& w : words) preTree.insert(w);

        vector<string> ans;
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        int i(0), j(0);
        for (i = 0; i < board.size(); ++i)
        {
            for (j = 0; j < board[0].size(); ++j)
            {
                if (preTree.root->m_node.count(board[i][j]) == 0) continue;
                searchWord(board, visited, preTree.root->m_node[board[i][j]], i, j, ans);
            }
        }
        
        return ans;
    }
private:
    void searchWord(const vector<vector<char>>& board, vector<vector<bool>>& visited, PrefixTrieNode* node, int x, int y, vector<string>& ans)
    {
        if (!(node->str.empty()))
        {
            ans.push_back(node->str);
            node->str.clear();
        }

        visited[x][y] = true;

        if (x > 0 && !visited[x - 1][y] && node->m_node.count(board[x - 1][y]) > 0) searchWord(board, visited, node->m_node[board[x - 1][y]], x - 1, y, ans);
        if (x + 1 < board.size() && !visited[x + 1][y] && node->m_node.count(board[x + 1][y]) > 0) searchWord(board, visited, node->m_node[board[x + 1][y]], x + 1, y, ans);
        if (y > 0 && !visited[x][y - 1] && node->m_node.count(board[x][y - 1]) > 0) searchWord(board, visited, node->m_node[board[x][y - 1]], x, y - 1, ans);
        if (y + 1 < board[0].size() && !visited[x][y + 1] && node->m_node.count(board[x][y + 1]) > 0) searchWord(board, visited, node->m_node[board[x][y + 1]], x, y + 1, ans);

        visited[x][y] = false;
    }
};

