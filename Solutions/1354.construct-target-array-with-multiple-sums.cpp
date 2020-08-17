/*
 * @lc app=leetcode id=1354 lang=cpp
 *
 * [1354] Construct Target Array With Multiple Sums
 */

// @lc code=start
class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<int> pq;
        long sum(0);
        for (int num : target) {
            pq.push(num);
            sum += num;
        }
        while (true) {
            int tmp(pq.top());
            //cout << tmp << ' ' << sum << endl;
            pq.pop();
            sum -= tmp;
            if (tmp == 1 || sum == 1) { return true; }
            if (tmp < sum || sum == 0) { return false; }
            tmp %= sum;
            if (tmp <= 0) { return false; }
            sum += tmp;
            pq.push(tmp);
            //cout << tmp << ' ' << sum << endl;
        }
        return false;
    }
};
// @lc code=end

