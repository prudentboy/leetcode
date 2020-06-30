/*
 * @lc app=leetcode id=835 lang=cpp
 *
 * [835] Image Overlap
 */

// @lc code=start
class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int ans(0);
        int i(0), j(0), n(A.size());
        vector<pair<int, int>> vA, vB;
        unordered_map<string, int> m;
        for (i = 0; i < n; ++i) {
            for (j = 0; j < n; ++j) {
                if (A[i][j] == 1) {
                    vA.push_back({i, j});
                }
                if (B[i][j] == 1) {
                    vB.push_back({i, j});
                }
            }
        }
        for (i = 0; i < vA.size(); ++i) {
            for (j = 0; j < vB.size(); ++j) {
                ++m[genKey(vA[i].first - vB[j].first, vA[i].second - vB[j].second)];
            }
        }
        for (auto& p : m) {
            ans = max(ans, p.second);
        }
        return ans;
    }
private:
    inline string genKey(int x, int y) {
        string ans(to_string(x));
        ans += ' ';
        ans.append(to_string(y));
        return ans;
    }
};
// @lc code=end

