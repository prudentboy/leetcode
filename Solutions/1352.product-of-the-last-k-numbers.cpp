/*
 * @lc app=leetcode id=1352 lang=cpp
 *
 * [1352] Product of the Last K Numbers
 */

// @lc code=start
class ProductOfNumbers {
public:
    ProductOfNumbers() : products_(1, 1) {}

    void add(int num) {
        if (num == 0) {
            products_.clear();
            products_.emplace_back(1);
            return;
        }
        products_.emplace_back(products_.back() * num);
    }
    
    int getProduct(int k) {
        if (k >= products_.size()) { return 0; }
        return products_.back() / products_[products_.size() - k - 1];
    }
private:
    vector<int> products_;
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
// @lc code=end

