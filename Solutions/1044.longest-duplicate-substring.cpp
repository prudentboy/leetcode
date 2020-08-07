/*
 * @lc app=leetcode id=1044 lang=cpp
 *
 * [1044] Longest Duplicate Substring
 */

// @lc code=start
class Solution {
public:
    string longestDupSubstring(string S) {
        int left(1), right(S.size() - 1), mid(0);
        string ans;
        while (left <= right) {
            mid = left + ((right - left) >> 1);
            if (!haskLenDupSubstr(S, mid, ans)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
private:
    unordered_map<int, long> memo;
    static constexpr long M = 1LL << 32;
    bool haskLenDupSubstr(string_view str, int k, string& ans) {
        int len(0);
        unsigned long hashNum(0);
        unordered_map<long, vector<int>> ump;
        for (int i(0); i < str.size(); ++i) {
            hashNum = (hashNum * 26 + str[i] - 'a') % M;
            if (++len > k) {
                hashNum = (hashNum + M - (str[i - k] - 'a') * myPow(k)) % M;
                --len;
            }
            if (len < k) { continue; }
            if (ump.count(hashNum) > 0) {
                for (int idx : ump[hashNum]) {
                    if (str.substr(idx, k) == str.substr(i - k + 1, k)) {
                        ans.assign(str.substr(idx, k));
                        return true;
                    }
                }
            }
            ump[hashNum].push_back(i - k + 1);
        }
        return false;
    }
    long myPow(int idx) {
        if (idx == 0) { return 1LL; }
        if (memo.count(idx) > 0) { return memo[idx]; }
        return memo[idx] = 26 * myPow(idx - 1) % M;
    }
};
// @lc code=end

