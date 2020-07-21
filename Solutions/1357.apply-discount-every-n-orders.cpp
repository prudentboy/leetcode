/*
 * @lc app=leetcode id=1357 lang=cpp
 *
 * [1357] Apply Discount Every n Orders
 */

// @lc code=start
class Cashier {
public:
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) : n_(n), dis_(discount), cnt_(0) {
        for (int i(0); i < prices.size(); ++i) { items_[products[i]] = prices[i]; }
    }
    
    double getBill(vector<int> product, vector<int> amount) {
        double bill(0.0);
        ++cnt_;
        for (int i(0); i < amount.size(); ++i) { bill += items_[product[i]] * amount[i]; }
        if (cnt_ == n_) {
            cnt_ = 0;
            bill *= 1 - (double)dis_ / 100;
        }
        return bill;
    }
private:
    int n_;
    int dis_;
    int cnt_;
    unordered_map<int, int> items_;
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */
// @lc code=end

