/*
 * @lc app=leetcode id=1286 lang=cpp
 *
 * [1286] Iterator for Combination
 */

// @lc code=start
class CombinationIterator {
public:
    CombinationIterator(string characters, int combinationLength) {
        string cur;
        function<void(int)> dfs = [&](int idx) {
            if (cur.size() == combinationLength) {
                q_.push(cur);
                return;
            }
            for (int i(idx); i < characters.size(); ++i) {
                cur += characters[i];
                dfs(i + 1);
                cur.pop_back();
            }
        };

        dfs(0);
    }
    
    string next() {
        string ret(q_.front());
        q_.pop();
        return ret;
    }
    
    bool hasNext() {
        return !q_.empty();
    }
private:
    queue<string> q_;
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
// @lc code=end

