/*
 * @lc app=leetcode id=854 lang=cpp
 *
 * [854] K-Similar Strings
 */

// @lc code=start
class Solution {
public:
    int kSimilarity(string A, string B) {
        int ans(0);
        if (A == B) { return ans; }

        unordered_set<string> visited;
        queue<string> q;
        q.push(A);
        visited.insert(A);

        while(!q.empty()) {
            int len(q.size());
            while (len-- > 0) {
                string cur(q.front());
                q.pop();
                if (cur == B) { return ans; }
                int i(0);
                while (i < A.size() && cur[i] == B[i]) { ++i; }
                for (int j(i + 1); j < A.size(); ++j) {
                    if (cur[j] == B[j] || cur[j] != B[i]) { continue; }
                    swap(cur[j], cur[i]);
                    if (visited.count(cur) == 0) {
                        q.push(cur);
                        visited.insert(cur);
                    }
                    swap(cur[j], cur[i]);
                }
            }
            ++ans;
        }

        return ans;
    }
};
// @lc code=end

