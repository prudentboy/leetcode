/*
 * @lc app=leetcode id=638 lang=cpp
 *
 * [638] Shopping Offers
 */

// @lc code=start
class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int m(price.size()), n(special.size());
        int ans(0), tmp(0);
        int i(0), j(0);
        for (i = 0; i < m; ++i) ans += price[i] * needs[i];
        vector<int> use(m, 0);
        for (const auto& sp : special)
        {
            for (i = 0; i < m; ++i)
            {
                if (sp[i] > needs[i]) break;
            }
            //cout << i << ' ' << n << endl;
            if (i == m)
            {
                for (j = 0; j < m; ++j) needs[j] -= sp[j];
                ans = min(ans, shoppingOffers(price, special, needs) + sp.back());
                for (j = 0; j < m; ++j) needs[j] += sp[j];
            }
        }
        return ans;
    }
};
// @lc code=end

