/*
 * @lc app=leetcode id=887 lang=cpp
 *
 * [887] Super Egg Drop
 */

// @lc code=start
class Solution {
public:
    int superEggDrop(int K, int N) {
        vector<vector<int>> memo(K + 1, vector<int>(N + 1));

        function<int(int, int)> eggDrop = [&](int cnt, int floor) {
            //cout << cnt << ' ' << floor << endl;
            if (cnt < 0 || floor < 0) { return 0; }
            if (cnt == 1) { return floor; }
            if (floor == 1) { return 1; }
            if (memo[cnt][floor] != 0) { return memo[cnt][floor]; }
            int mn(floor);
            int left(2), right(floor - 1), mid(0);
            while (left <= right) {
                mid = left + ((right - left) >> 1);
                if (eggDrop(cnt - 1, mid - 1) >= eggDrop(cnt, floor - mid)) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            mn = min(mn, max(eggDrop(cnt - 1, left - 1), eggDrop(cnt, floor - left)) + 1);
            /*
            for (int i(2); i < floor; ++i) {
                mn = min(mn, max(eggDrop(cnt - 1, i - 1), eggDrop(cnt, floor - i)) + 1);
            }
            */
            return memo[cnt][floor] = mn;
        };

        return eggDrop(K, N);
    }
};
// @lc code=end

