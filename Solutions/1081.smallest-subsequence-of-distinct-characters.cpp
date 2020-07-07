/*
 * @lc app=leetcode id=1081 lang=cpp
 *
 * [1081] Smallest Subsequence of Distinct Characters
 */

// @lc code=start
class Solution {
public:
    string smallestSubsequence(string text) {
        unordered_map<char, int> cntUmp, useUmp;
        for (char c : text) {
            ++cntUmp[c];
            useUmp[c] = 0;
        }

        deque<char> dq;
        for (char c : text) {
            while (!dq.empty() && useUmp[c] == 0 && cntUmp[dq.back()] > 0 && c < dq.back()) {
                useUmp[dq.back()] = 0;
                dq.pop_back();
            }
            --cntUmp[c];
            if (useUmp[c] == 0) {
                dq.push_back(c);
                useUmp[c] = 1;
            }
        }

        string ans;
        while (!dq.empty()) {
            ans += dq.front();
            dq.pop_front();
        }
        return ans;
    }
};
// @lc code=end

