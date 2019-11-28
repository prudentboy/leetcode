/*
 * @lc app=leetcode id=870 lang=cpp
 *
 * [870] Advantage Shuffle
 */

// @lc code=start
class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        int n(A.size());
        vector<int> ans(n, 0);

        multiset<int> ms(A.begin(), A.end());
        auto it = ms.begin();
        for (int i(0); i < n; ++i)
        {
            it = ms.upper_bound(B[i]);
            if (it == ms.end()) it = ms.begin();
            ans[i] = *it;
            ms.erase(it);
        }
        return ans;
    }
};
// @lc code=end

