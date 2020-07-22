/*
 * @lc app=leetcode id=1268 lang=cpp
 *
 * [1268] Search Suggestions System
 */

// @lc code=start
class Solution {
struct Trie {
    Trie() : children_(26, nullptr) {}
    ~Trie() {
        for (Trie* child : children_) {
            if (child != nullptr) { delete child; }
        }
    }
    void add(const string& product) {
        Trie* tmp(this);
        for (char c : product) {
            if (tmp->children_[c - 'a'] == nullptr) { tmp->children_[c - 'a'] = new Trie(); }
            tmp = tmp->children_[c - 'a'];
            if (tmp->words_.size() < 3) { tmp->words_.push_back(product); }
        }
    }
    vector<vector<string>> search(const string& word) {
        Trie* tmp(this);

        vector<vector<string>> ret(word.size());
        int idx(0);
        for (char c : word) {
            if (tmp->children_[c - 'a'] == nullptr) { break; }
            tmp = tmp->children_[c - 'a'];
            for (auto& product : tmp->words_) { ret[idx].push_back(product); }
            ++idx;
        }
        return ret;
    }
    vector<Trie*> children_;
    vector<string> words_;
};
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        Trie productTrie;
        for (auto& product : products) { productTrie.add(product); }
        return productTrie.search(searchWord);
    }
};
// @lc code=end

