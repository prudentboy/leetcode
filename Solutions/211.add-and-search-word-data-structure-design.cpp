/*
 * @lc app=leetcode id=211 lang=cpp
 *
 * [211] Add and Search Word - Data structure design
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

class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(const string& word) {
        TrieNode* tmp(root);
        for (const char& c : word)
        {
            if (tmp->child[c - 'a'] == nullptr) tmp->child[c - 'a'] = new TrieNode();
            tmp = tmp->child[c - 'a'];
        }
        tmp->isWord = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(const string& word) {
        return search(word, 0, root);
    }
private:
    TrieNode* root;
    bool search(const string& word, size_t index, TrieNode* now)
    {
        if (index == word.size()) return now->isWord;
        const char& c(word[index]);
        if (c != '.')
        { 
            if (now->child[c - 'a'] == nullptr) return false;
            return search(word, index + 1, now->child[c - 'a']);
        }
        for (int i(0); i < 26; ++i)
        {
            if (now->child[i] == nullptr) continue;
            if (search(word, index + 1, now->child[i])) return true;
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

