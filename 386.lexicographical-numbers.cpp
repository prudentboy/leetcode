/*
 * @lc app=leetcode id=386 lang=cpp
 *
 * [386] Lexicographical Numbers
 */

// @lc code=start
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans(n, 0);
        int cur(1);
        for (int i(0); i < n; ++i)
        {
            ans[i] = cur;
            if (cur * 10 <= n) cur *= 10;
            else
            {
                if (cur >= n) cur /= 10;
                ++cur;
                while (cur % 10 == 0) cur /= 10;
            }
            
            //cout << i << ' ' << cur << endl; 
        }
        return ans;
    }
};
// @lc code=end
