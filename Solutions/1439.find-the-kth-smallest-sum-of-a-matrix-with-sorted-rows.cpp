/*
 * @lc app=leetcode id=1439 lang=cpp
 *
 * [1439] Find the Kth Smallest Sum of a Matrix With Sorted Rows
 */

// @lc code=start
class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        const int m(mat.size()), n(mat[0].size());
        priority_queue<vector<int>> pq;
        vector<int> node(m + 1);
        for (int i(0); i < m; ++i) { node[0] -= mat[i][0]; }
        pq.push(node);
        set<vector<int>> s;
        s.insert(node);
        while (!pq.empty()) {
            vector<int> cur(pq.top());
            pq.pop();
            if (--k == 0) { return -cur.front(); }
            for (int i(0); i < m; ++i) {
                if (cur[i + 1] == n - 1) { continue; }
                vector<int> nxt(cur);
                ++nxt[i + 1];
                nxt.front() -= (mat[i][nxt[i + 1]] - mat[i][nxt[i + 1] - 1]);
                if (!s.insert(nxt).second) { continue; }
                pq.push(move(nxt));
            }
        }
        return -1;
    }
};
// @lc code=end

