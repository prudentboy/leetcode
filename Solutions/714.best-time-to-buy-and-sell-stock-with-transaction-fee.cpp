/*
 * @lc app=leetcode id=714 lang=cpp
 *
 * [714] Best Time to Buy and Sell Stock with Transaction Fee
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        if (prices.empty()) return 0;
        int hold(-prices[0]), sell(0);
        int tmp(0);
        for (int p : prices)
        {
            tmp = sell;
            sell = max(sell, hold + p - fee);
            hold = max(hold, tmp - p);
        }
        return sell;
    }
};
// @lc code=end

