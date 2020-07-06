/*
 * @lc app=leetcode id=1475 lang=cpp
 *
 * [1475] Final Prices With a Special Discount in a Shop
 */

// @lc code=start
class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int*> stk;
        for (int& p : prices) {
            while (!stk.empty() && *(stk.top()) >= p) {
                *(stk.top()) -= p;
                stk.pop();
            }
            stk.push(&p);
        }
        return prices;
    }
};
// @lc code=end

