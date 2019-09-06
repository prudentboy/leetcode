/*
 * @lc app=leetcode id=123 lang=cpp
 *
 * [123] Best Time to Buy and Sell Stock III
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) return 0;

        int b1(-prices[0]), b2(-prices[0]), s1(0), s2(0);

        for (int i(1); i < prices.size(); ++i)
        {
            if (-prices[i] > b1) b1 = -prices[i];
            if (b1 + prices[i] > s1) s1 = b1 + prices[i];
            if (s1 - prices[i] > b2) b2 = s1 - prices[i];
            if (b2 + prices[i] > s2) s2 = b2 + prices[i];
        }

        return s2;
    }
};

