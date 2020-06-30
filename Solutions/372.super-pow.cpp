/*
 * @lc app=leetcode id=372 lang=cpp
 *
 * [372] Super Pow
 */

// @lc code=start
class Solution {
public:
    int superPow(int a, vector<int>& b) {
        if (a == 0) return 0;

        int ans(1);
        for (int i(0); i < b.size(); ++i)
        {
            ans = ((pow(ans, 10) % 1337) * (pow(a, b[i]) % 1337)) % 1337;
        }
        return ans;
    }
private:
    int pow(int a, int b)
    {
        if (a == 1 || b == 0) return 1;
        if (b == 1) return a % 1337;
        return ((pow(a, (b >> 1)) % 1337) * (pow(a, b - (b >> 1)) % 1337)) % 1337;
    }
};
// @lc code=end

