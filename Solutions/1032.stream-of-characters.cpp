/*
 * @lc app=leetcode id=1032 lang=cpp
 *
 * [1032] Stream of Characters
 */

// @lc code=start
class StreamChecker {
struct Trie {
    Trie() : children(26, nullptr), isWord(false) {}
    ~Trie() { for (Trie* child : children) { if (child != nullptr) { delete child; } } }
    vector<Trie*> children;
    bool isWord;
};
public:
    StreamChecker(vector<string>& words) : dict_(new Trie()) {
        stream_.reserve(40000);
        for (auto& word : words) { addWord(word); }
    }
    
    bool query(char letter) {
        stream_ += letter;
        return search();
    }
private:
    void addWord(string_view word) {
        Trie* tmp(dict_);
        for (int j(word.size() - 1); j >= 0; --j) {
            if (tmp->children[word[j] - 'a'] == nullptr) { tmp->children[word[j] - 'a'] = new Trie(); }
            tmp = tmp->children[word[j] - 'a'];
        }
        tmp->isWord = true;
    }
    bool search() {
        Trie* tmp(dict_);
        for (int j(stream_.size() - 1); j >= 0; --j) {
            tmp = tmp->children[stream_[j] - 'a'];
            if (tmp == nullptr) { return false; }
            if (tmp->isWord) { return true; }
        }
        return false;
    } 
private:
    string stream_;
    Trie* dict_;
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
// @lc code=end

