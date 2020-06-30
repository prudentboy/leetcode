/*
 * @lc app=leetcode id=648 lang=cpp
 *
 * [648] Replace Words
 */

// @lc code=start
class Solution {
public:
    struct TrieNode
    {
        bool isWord;
        TrieNode* children[26];
        TrieNode() : isWord(false)
        {
            for (auto& c : children) c = nullptr;
        }
    };

    string replaceWords(vector<string>& dict, string sentence) {
        TrieNode* root = new TrieNode();
        for (const string& s : dict) updateTrie(root, s);
        size_t pos(0), pre(0);
        pos = sentence.find_first_of(" ");
        string word, succ;
        string ans;
        while (pos != string::npos)
        {
            if (pre != pos)
            {
                word.assign(sentence.substr(pre, pos - pre));
                succ = getSucc(root, word);
                ans.append(succ);
                ans += ' ';
                //cout << word << ' ' << succ << endl;
            }
            pre = pos + 1;
            pos = sentence.find_first_of(" ", pre);
        }
        word.assign(sentence.substr(pre));
        succ = getSucc(root, word);
        ans.append(succ);
        return ans;
    }
private:
    void updateTrie(TrieNode* root, const string& s)
    {
        for (const char c : s)
        {
            if (root->children[c - 'a'] == nullptr) root->children[c - 'a'] = new TrieNode();
            root = root->children[c - 'a'];
        }
        root->isWord = true;
    }
    string getSucc(TrieNode* root, const string& s)
    {
        TrieNode* tmp(root);
        for (int i(0); i < s.size(); ++i)
        {
            if (tmp->children[s[i] - 'a'] == nullptr) return s;
            tmp = tmp->children[s[i] - 'a'];
            if (tmp->isWord) return s.substr(0, i + 1);
        }
        return s;
    }
};
// @lc code=end

