/*
 * @lc app=leetcode id=798 lang=cpp
 *
 * [798] Smallest Rotation with Highest Score
 */

// @lc code=start
class Solution {
public:
    int bestRotation(vector<int>& A) {
        int n(A.size());
        vector<int> bad(n, 0);
        for (int i(0); i < n; ++i) { bad[(i - A[i] + 1 + n) % n] -= 1; }
        //for (int i(0); i < n; ++i) { cout << bad[i] << ' '; }
        //cout << endl;
        for (int i(1); i < n; ++i) { bad[i] += bad[i - 1] + 1; }
        //for (int i(0); i < n; ++i) { cout << bad[i] << ' '; }
        return max_element(bad.begin(), bad.end()) - bad.begin();
    }
};
// @lc code=end

