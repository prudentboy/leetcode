/*
 * @lc app=leetcode id=685 lang=cpp
 *
 * [685] Redundant Connection II
 */

// @lc code=start
class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        vector<int> ans1, ans2;

        int n(edges.size() + 1);
        vector<int> parents(n, 0), roots(n, 0), sizes(n, 1);

        int p(0), c(0);
        for (auto& edge : edges) {
            p = edge[0];
            c = edge[1];

            if (parents[c] > 0 && parents[c] != p) {
                ans1 = {parents[c], c};
                ans2 = edge;

                edge[0] = edge[1] = 0;
                break;
            }

            parents[c] = p;
        }

        int rp(0);
        int rc(0);
        for (auto& edge : edges) {
            p = edge[0];
            c = edge[1];

            if (p == 0 && c == 0) { continue; }

            if (roots[p] == 0) { roots[p] = p; }
            if (roots[c] == 0) { roots[c] = c; }

            rp = find(roots, p);
            rc = find(roots, c);

            if (rp == rc) { return ans1.empty() ? edge : ans1; }
            
            if (sizes[rp] < sizes[rc]) { swap(rp, rc); }

            roots[rc] = rp;
            ++sizes[rc];
        }

        return ans2;
    }
private:
    int find(vector<int>& roots, int n) {
        while (roots[n] != n) {
            roots[n] = roots[roots[n]];
            n = roots[n];
        }
        return n;
    }
};
// @lc code=end

