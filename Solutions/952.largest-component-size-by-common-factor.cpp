/*
 * @lc app=leetcode id=952 lang=cpp
 *
 * [952] Largest Component Size by Common Factor
 */

// @lc code=start
class Solution {
public:
    int largestComponentSize(vector<int>& A) {
        int mx(A.front());
        for (int i(1); i < A.size(); ++i) { mx = max(mx, A[i]); }

        vector<int> parents(mx + 1);
        iota(parents.begin(), parents.end(), 0);

        function<int(int)> find = [&](int idx) -> int {
            if (parents[idx] != idx) { parents[idx] = find(parents[idx]); }
            return parents[idx];
        };

        for (int a : A) {
            int sq(sqrt(a));
            for (int i(2); i <= sq; ++i) {
                if (a % i == 0) {
                    int ap(find(a));
                    int ip(find(i));
                    int fp(find(a / i));
                    parents[ip] = ap;
                    parents[fp] = ap;
                }
            }
        }

        int ans(1);
        unordered_map<int, int> unions;
        for (int a : A) {
            ans = max(ans, ++unions[find(a)]);
        }
        return ans;
    }
};
// @lc code=end

