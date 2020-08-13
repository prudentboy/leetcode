/*
 * @lc app=leetcode id=1467 lang=cpp
 *
 * [1467] Probability of a Two Boxes Having The Same Number of Distinct Balls
 */

// @lc code=start
class Solution {
public:
    double getProbability(vector<int>& balls) {
        vector<double> factorial(49);
        factorial[0] = factorial[1] = 1;
        function<double(int)> getFactor = [&](int i) {
            if (factorial[i] > 0) { return factorial[i]; }
            return factorial[i] = getFactor(i - 1) * i;
        };

        int sum(0);
        for (int ball : balls) { sum += ball; }
        double total(getFactor(sum));
        for (int ball : balls) { total /= getFactor(ball); }

        vector<int> one(balls.size()), another(balls.size());

        double hit(0.0);
        function<void(int, int)> dfs = [&](int idx, int cnt) {
            if (cnt > (sum >> 1)) { return; }
            if (idx == balls.size()) {
                if (cnt != (sum >> 1)) { return; }
                int diff1(0), diff2(0);
                double p(getFactor(sum >> 1));
                p *= p;
                for (int i(0); i < balls.size(); ++i) {
                    p /= getFactor(one[i]);
                    p /= getFactor(another[i]);
                    if (one[i] > 0) { ++diff1; }
                    if (another[i] > 0) { ++diff2; }
                }
                if (diff1 == diff2) { hit += p; }
                return;
            }
            for (int i(0); i <= balls[idx]; ++i) {
                one[idx] = i;
                another[idx] = balls[idx] - i;
                dfs(idx + 1, cnt + i);
            }
        };

        dfs(0, 0);
        return hit / total;
    }
};
// @lc code=end

