/*
 * @lc app=leetcode id=1386 lang=cpp
 *
 * [1386] Cinema Seat Allocation
 */

// @lc code=start
class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int ans(0);
        unordered_map<int, int> seats;
        for (auto& rs : reservedSeats) { seats[rs[0]] |= 1 << (rs[1] - 1); }
        for (auto& p : seats) {
            int& rs(p.second);
            if ((rs & 0x1fe) == 0) {
                ans += 2;
            } else if ((rs & 0x78) == 0 || (rs & 0x1e0) == 0 || (rs & 0x1e) == 0) {
                ++ans;
            }
            //cout << rs << ' ' << ans << endl;
        }
        ans += (n - seats.size()) << 1;
        return ans;
    }
};
// @lc code=end

