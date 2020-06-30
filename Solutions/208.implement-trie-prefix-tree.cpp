/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 */
class TrieNode
{
public:
    bool isWord;
    TrieNode* child[26];
public:
    TrieNode() : isWord(false)
    {
        for (int i(0); i < 26; ++i) child[i] = nullptr;
    }
};

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(const string& word) {
        TrieNode* tmp(root);
        size_t index(0);
        for (char c : word)
        {
            index = c - 'a';
            if (tmp->child[index] == nullptr) tmp->child[index] = new TrieNode();
            tmp = tmp->child[index];
        }
        tmp->isWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(const string& word) {
        TrieNode* tmp(root);
        size_t index(0);
        for (char c : word)
        {
            index = c - 'a';
            if (tmp->child[index] == nullptr) return false;
            tmp = tmp->child[index];
        }
        return tmp->isWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(const string& prefix) {
        TrieNode* tmp(root);
        size_t index(0);
        for (char c : prefix)
        {
            index = c - 'a';
            if (tmp->child[index] == nullptr) return false;
            tmp = tmp->child[index];
        }
        return true;
    }
private:
    TrieNode* root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

