/*
 * @lc app=leetcode id=1307 lang=cpp
 *
 * [1307] Verbal Arithmetic Puzzle
 */

// @lc code=start
class Solution {
public:
    bool isSolvable(vector<string>& words, string result) {
        unordered_set<char> ust;
        for (string& word : words) {
            if (word.size() > result.size()) { return false; }
            for (char c : word) { ust.insert(c); }
        }
        for (char c : result) { ust.insert(c); }
        
        const int n(ust.size());
        int i(0);
        unordered_map<char, int> ump;
        for (char c : ust) { ump[c] = i++; }

        vector<int> nums(n);
        auto getNum = [&](string_view word) -> int {
            cout << word << ':' << endl;
            if (word.size() > 1 && nums[ump[word.front()]] == 0) { return -1; }
            int ret(0);
            for (char c : word) {
                ret *= 10;
                ret += nums[ump[c]];
            }
            cout << ' ' << ret << endl;
            return ret;
        };
        auto check = [&]() -> bool {
            for (char c : ust) {
                cout << c << ':' << nums[ump[c]] << endl;
            }
            const int m(words.size());
            vector<int> word_nums;
            for (auto& word : words) { word_nums.push_back(getNum(word)); }
            int result_num(getNum(result));
            int sum(0);
            for (int num : word_nums) {
                if (num < 0) { return false; }
                sum += num;
            }
            return sum == result_num;
        };

        vector<bool> visited(10, false);
        function<bool(int)> dfs = [&](int idx) {
            cout << idx << endl;
            if (idx == n) { return check(); }
            for (int i(0); i < 10; ++i) {
                if (visited[i]) { continue; }
                nums[idx] = i;
                visited[i] = true;
                if (dfs(idx + 1)) { return true; }
                visited[i] = false;
            }
            return false;
        };

        return dfs(0);
    }
};
// @lc code=end

