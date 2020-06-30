/*
 * @lc app=leetcode id=188 lang=cpp
 *
 * [188] Best Time to Buy and Sell Stock IV
 */
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.size() < 2 or k < 1) return 0;
        
        if (k > prices.size() / 2 + 1) k = prices.size() / 2 + 1;
        vector<int> buy(k, -prices[0]);
        vector<int> sell(k);

        for (int i(1); i < prices.size(); ++i)
        {
            if (-prices[i] > buy[0]) buy[0] = -prices[i];
            if (buy[0] + prices[i] > sell[0]) sell[0] = buy[0] + prices[i];
            for (int j(1); j < k; ++j)
            {
                if (sell[j - 1] - prices[i] > buy[j]) buy[j] = sell[j - 1] - prices[i];
                if (buy[j] + prices[i] > sell[j]) sell[j] = buy[j] + prices[i];
            }
        } 

        return sell[k - 1];
    }
};

