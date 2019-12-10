/*
 * @lc app=leetcode id=873 lang=cpp
 *
 * [873] Length of Longest Fibonacci Subsequence
 */

// @lc code=start
class Solution {
public:
    int lenLongestFibSubseq(vector<int>& A) {
        int ans(2);
        int i(0), j(0), n(A.size());
        unordered_set<int> s(A.begin(), A.end());
        for (i = 0; i < n - 2; ++i) {
            for (j = i + 1; j < n - 1; ++j) {
                ans = max(ans, cntFibLen(A[i], A[j], s));
            }
        }
        return ans > 2 ? ans : 0;
    }
private:
    int cntFibLen(int pre, int now, const unordered_set<int>& s) {
        //cout << pre << ' ' << now << ' ';
        int next(pre + now), len(2);
        while (s.count(next) > 0) {
            ++len;
            pre = now;
            now = next;
            next = now + pre;
        }
        //cout << len << endl;
        return len;
    }
};
// @lc code=end

