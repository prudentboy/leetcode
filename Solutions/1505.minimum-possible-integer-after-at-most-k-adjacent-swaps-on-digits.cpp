/*
 * @lc app=leetcode id=1505 lang=cpp
 *
 * [1505] Minimum Possible Integer After at Most K Adjacent Swaps On Digits
 */

// @lc code=start
class FenWick {
public:
    FenWick(const int n) : sums_(n + 1) {}
    void update(int idx, int delta) {
        ++idx;
        while (idx < sums_.size()) {
            sums_[idx] += delta;
            idx += idx & (-idx);
        }
    }
    int query(int idx) {
        int ret(0);
        ++idx;
        while (idx > 0) {
            ret += sums_[idx];
            idx -= idx & (-idx);
        }
        return ret;
    }
private:
    vector<int> sums_;
};
class Solution {
public:
    string minInteger(string num, int k) {
        const int n(num.size());
        vector<queue<int>> pos(10);
        for (int i(0); i < n; ++i) { pos[num[i] - '0'].push(i); }
        
        FenWick prefixSum(n);
        vector<bool> modified(n, false);
        string ans;
        while (k > 0 && ans.size() < n) {
            for (int i(0); i < 10; ++i) {
                if (pos[i].empty()) { continue; }
                int cost(pos[i].front() - prefixSum.query(pos[i].front() - 1));
                if (cost > k) { continue; }
                prefixSum.update(pos[i].front(), 1);
                k -= cost;
                ans += num[pos[i].front()];
                modified[pos[i].front()] = true;
                pos[i].pop();
                break;
            }
        }
        
        for (int i(0); i < n; ++i) {
            if (modified[i]) { continue; }
            ans += num[i];
        }
        
        return ans;
    }
};
// @lc code=end

