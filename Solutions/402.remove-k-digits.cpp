/*
 * @lc app=leetcode id=402 lang=cpp
 *
 * [402] Remove K Digits
 */

// @lc code=start
class Solution {
public:
    string removeKdigits(string num, int k) {
        if (num.empty() || k >= num.size()) return "0";
        
        string ans(1, num[0]);
        for (int i(1); i < num.size(); ++i)
        {
            while (!ans.empty() && k > 0 && num[i] < ans.back())
            {
                ans.pop_back();
                --k;
            }
            ans += num[i];
        }
        //cout << ans << endl;
        if (k > 0) ans.resize(ans.size() - k);
        while (ans.front() == '0') ans.erase(ans.begin());
        return ans.empty() ? "0" : ans;
    }
};
// @lc code=end

