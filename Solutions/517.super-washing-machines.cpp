/*
 * @lc app=leetcode id=517 lang=cpp
 *
 * [517] Super Washing Machines
 */

// @lc code=start
class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int n(machines.size());
        if (n <= 1) { return 0; }
        
        int sum(accumulate(machines.begin(), machines.end(), 0));
        if (sum % n != 0) { return -1; }

        int ans(0);
        int i(0), total(0), need(0);
        for (i = 0; i < n; ++i) {
            total += machines[i];
            need += sum / n;
            ans = max(ans, max(abs(total - need), machines[i] - sum / n));
            //cout << total << ' ' << need << ' ' << ans << endl;
        }

        return ans;
    }
};
// @lc code=end

